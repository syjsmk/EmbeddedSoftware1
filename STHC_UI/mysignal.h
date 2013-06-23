#ifndef MYSIGNAL_H
#define MYSIGNAL_H

#define signal_IOCTL_NUM	'x'
#define IOCTL_START_NUM	0x80

#define IOCTL_NUM1		IOCTL_START_NUM+3
#define IOCTL_NUM2		IOCTL_START_NUM+4
#define IOCTL_NUM3		IOCTL_START_NUM+5

#define signal_ioctl1			_IOWR(signal_IOCTL_NUM,IOCTL_NUM1,unsigned long *)
#define signal_ioctl2			_IOWR(signal_IOCTL_NUM,IOCTL_NUM2,unsigned long *)
#define signal_ioctl3			_IOWR(signal_IOCTL_NUM,IOCTL_NUM3,unsigned long *)

#define IRQ_UP               177
#define IRQ_DOWN          174
#define IRQ_LEFT            175


#endif // MYSIGNAL_H
