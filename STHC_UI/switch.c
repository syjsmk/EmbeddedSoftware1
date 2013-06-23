#include <linux/delay.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/poll.h>
#include <linux/interrupt.h>
#include <asm/irq.h>
#include <asm/mach/irq.h>
#include <asm/mach/time.h>
#include <asm/hardware.h>
#include <asm/arch/pxa-regs.h>
#include <asm/arch/xhyper3xx.h>
#include <asm/arch/gpio.h>
#include <asm/arch/mfp.h>

#include <linux/cdev.h>
#include <linux/pid.h>
#include <linux/types.h>
#include <linux/signal.h>
#include <linux/fs.h>
#include <linux/fcntl.h>
#include <linux/sched.h>
#include <linux/wait.h>
#include <asm/uaccess.h>

#include "signal.h"

#define DEV_NAME "switch_dev"

#define IRQ_UP			IRQ_GPIO(MFP2GPIO(MFP_DIR_D_GPIO))
#define IRQ_DOWN		IRQ_GPIO(MFP2GPIO(MFP_DIR_A_GPIO))
#define IRQ_LEFT		IRQ_GPIO(MFP2GPIO(MFP_DIR_B_GPIO))

static dev_t dev_num;
static struct cdev *cd_cdev;

typedef struct uiStruct
{
	int sthc_pid;
	int irqnum;
	void *buf;
}uiStruct;

uiStruct us;

struct tasklet_struct switch_tasklet_struct; // tasklet struct

pid_t tv_pid;
pid_t hmng_pid;
int tvData;

struct tasklet_data 
{
	int irq;
};

struct tasklet_data switch_tasklet_data;

int usrSigno = SIGUSR2; // Signal number
struct task_struct *buftask;

static void sendKill1User(pid_t pid, int data)
{
	struct siginfo sinfo;
	// struct pid *bufpid;

	sinfo.si_signo = SIGUSR1;
	sinfo.si_errno = 0;
	sinfo.si_code = SI_MESGQ;
	sinfo.si_addr = 0;
	sinfo.si_value.sival_int = data;
	
	// 상대방 pid를 알아야할 필요가 있는가?
	// buftask = pid_task(find_vpid(pid), 0);
	// bufpid = task_pid(buftask);
	// bufpid = task_pid(current); // FIXME : there is no guarantee
	kill_proc_info_as_uid(SIGUSR1, &sinfo, pid, 0, 0);
}


static void sendKill2User(pid_t pid, int irq)
{
	struct siginfo sinfo;
	// struct pid *bufpid;

	sinfo.si_signo = usrSigno;
	sinfo.si_errno = 0;
	sinfo.si_code = SI_MESGQ;
	sinfo.si_addr = 0;
	sinfo.si_value.sival_int = irq;
	
	// 상대방 pid를 알아야할 필요가 있는가?
	// buftask = pid_task(find_vpid(pid), 0);
	// bufpid = task_pid(buftask);
	// bufpid = task_pid(current); // FIXME : there is no guarantee
	kill_proc_info_as_uid(usrSigno, &sinfo, pid, 0, 0);
}

void switch_tasklet_proc_function(unsigned long recvData)
{
	struct tasklet_data *tempData;

	tempData = (struct tasklet_data *)recvData;

	printk("taskelt_proc_function\n");
	if(tempData->irq == IRQ_UP) printk("Joystick Up / irq = %d\n", tempData->irq);	
	if(tempData->irq == IRQ_DOWN) printk("Joystick Down / irq = %d\n", tempData->irq);	
	if(tempData->irq == IRQ_LEFT) printk("Joystick Left / irq = %d\n", tempData->irq);
	
	// 상대 pid를 얻어야한다면, 어떻게 얻어올 것인가?
	// irq에 따라 다르게 보내줘야되나?
	
	if(tempData->irq == IRQ_UP || tempData->irq == IRQ_DOWN)
	{
		sendKill2User(tv_pid, tempData->irq);
		sendKill2User(hmng_pid, tempData->irq);
	}
	else if(tempData->irq == IRQ_LEFT)
	{
		sendKill2User(hmng_pid, tempData->irq);
	}
}

static irqreturn_t KEY_interrupt_hdr(int irq, void *dev_id, struct pt_regs *regs)
{
	mdelay(200);

	switch_tasklet_data.irq = irq;

	tasklet_init(&switch_tasklet_struct, switch_tasklet_proc_function, &switch_tasklet_data);
	tasklet_schedule(&switch_tasklet_struct);

	return IRQ_HANDLED;
}

static int signal_ioctl(struct inode *inode, struct file *fiop, unsigned int cmd, unsigned long arg)
{
	if(cmd < 0)
		return -1;

	switch(cmd)
	{
		case signal_ioctl1: // recv tv_pid
			copy_from_user(&tv_pid, (pid_t *)arg, sizeof(pid_t));
			printk("ioctl1: %d\n", tv_pid);
			break;
		case signal_ioctl2: // recv hmn
			copy_from_user(&hmng_pid, (pid_t *)arg, sizeof(pid_t));
			printk("ioctl2: %d\n", hmng_pid);
			break;
		case signal_ioctl3: // recv hmn
			copy_from_user(tvData, arg, sizeof(int));
			sendKill1User(tv_pid, tvData);
			printk("ioctl3: %d\n", tvData);
			break;
		default:
			break;
	}

	return cmd;
}

static int signal_open(struct inode *inode, struct file *fiop)
{
	printk("Device Open\n");
	return 0;
}

static int signal_release(struct inode *inode, struct file *fiop)
{
	printk("Release Driver\n");
	return 0;
}

struct file_operations switch_fops =
{
	.open= signal_open,
	.release = signal_release,
	.ioctl = signal_ioctl,
};

int __init init_mdd(void)
{
	int ret;
	// device driver 추가???
	ret = alloc_chrdev_region(&dev_num, 0, 1, DEV_NAME);

	cd_cdev = cdev_alloc();
	cdev_init(cd_cdev, &switch_fops);
	ret = cdev_add(cd_cdev, dev_num, 1);

	if(ret < 0)
		return -1;

	mhn_mfp_set_afds(MFP_DIR_D_GPIO, MFP_DIR_D_GPIO_AF, MFP_DS03X);
	mhn_gpio_set_direction(MFP_DIR_D_GPIO, GPIO_DIR_IN);
	
	mhn_mfp_set_afds(MFP_DIR_B_GPIO, MFP_DIR_B_GPIO_AF, MFP_DS03X);
	mhn_gpio_set_direction(MFP_DIR_B_GPIO, GPIO_DIR_IN);
	
	mhn_mfp_set_afds(MFP_DIR_A_GPIO, MFP_DIR_A_GPIO_AF, MFP_DS03X);
	mhn_gpio_set_direction(MFP_DIR_A_GPIO, GPIO_DIR_IN);

	if ((ret = request_irq(IRQ_UP, &KEY_interrupt_hdr, SA_INTERRUPT, "GPIO120_UP", NULL)))
	{
        	printk("Failed to register IRQ UP\n");
        	return ret;
	}
	
	if ((ret = request_irq(IRQ_DOWN, &KEY_interrupt_hdr, SA_INTERRUPT, "GPIO122_DOWN", NULL)))
	{
        	printk("Failed to register IRQ DOWN\n");
        	return ret;
	}
	
	if ((ret = request_irq(IRQ_LEFT, &KEY_interrupt_hdr, SA_INTERRUPT, "GPIO121_LEFT", NULL)))
	{
        	printk("Failed to register IRQ LEFT\n");
        	return ret;
	}
	/*
	mhn_mfp_set_afds(MFP_PUSH1_GPIO, MFP_PUSH1_GPIO_AF, MFP_DS03X);
	mhn_gpio_set_direction(MFP_PUSH1_GPIO, GPIO_DIR_IN);
	 
	mhn_mfp_set_afds(MFP_PUSH2_GPIO, MFP_PUSH2_GPIO_AF, MFP_DS03X);
	mhn_gpio_set_direction(MFP_PUSH1_GPIO, GPIO_DIR_IN);
	
	mhn_mfp_set_afds(MFP_PUSH3_GPIO, MFP_PUSH3_GPIO_AF, MFP_DS03X);
	mhn_gpio_set_direction(MFP_PUSH1_GPIO, GPIO_DIR_IN);
	
	mhn_mfp_set_afds(MFP_PUSH4_GPIO, MFP_PUSH4_GPIO_AF, MFP_DS03X);
	mhn_gpio_set_direction(MFP_PUSH1_GPIO, GPIO_DIR_IN);
	
	if ((ret = request_irq(IRQ_KEY1, &KEY_interrupt_hdr, SA_INTERRUPT, "GPIO115_KEY1", NULL)))
	{
        	printk("Failed to register IRQ KEY1\n");
        	return ret;
	}

	if ((ret = request_irq(IRQ_KEY2, &KEY_interrupt_hdr, SA_INTERRUPT, "GPIO116_KEY2", NULL)))
	{
        	printk("Failed to register IRQ KEY2\n");
        	return ret;
	}
	
	if ((ret = request_irq(IRQ_KEY3, &KEY_interrupt_hdr, SA_INTERRUPT, "GPIO117_KEY3", NULL)))
	{
        	printk("Failed to register IRQ KEY3\n");
        	return ret;
	}

	if ((ret = request_irq(IRQ_KEY4, &KEY_interrupt_hdr, SA_INTERRUPT, "GPIO118_KEY4", NULL)))
	{
        	printk("Failed to register IRQ KEY4\n");
        	return ret;
	}
	*/
	return 0;
}

void __exit exit_mdd(void)
{
	tasklet_kill(&switch_tasklet_struct);
	
	cdev_del(cd_cdev);
	unregister_chrdev_region(dev_num, 1);	
}

module_init(init_mdd);
module_exit(exit_mdd);
MODULE_LICENSE("GPL");
