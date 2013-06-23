#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/ioctl.h>

#include "signal.h"

#define MAXCH 		8
#define MINCH 		1
#define MAXVOL 		100
#define MINVOL 		0

#define IRQ_UP		177
#define IRQ_DOWN	174

int ch;
int vol;
pid_t tv_pid;

void sig_handler(int signo, siginfo_t *info, void *context)
{
	int val = (int *)(info->si_value.sival_int);
	
	printf("sdjfdajfldjalfkjdslajflsajdlkf=%d", val);

	switch(val)
	{
		case IRQ_UP:
			if(ch < MAXCH)
			{	
				ch++;
				printf("ch :%d\n", ch);
			}
			if(ch == MAXCH)
			{
				ch = MINCH;
				printf("ch :%d\n", ch);
			}
			break;
		case IRQ_DOWN:
			if(ch > MINCH)
			{
				ch--;
				printf("ch :%d\n", ch);
			}
			if(ch == MINCH)
			{
				ch = MAXCH;  
				printf("ch :%d\n", ch); 
			}
			break;
	/*	case vol_up:
			if(vol < MAXVOL)
			{	
				vol++;
			}
			break;
		case vol_down:
			if(vol > MINVOL)
			{
				vol--;
			}
			break;*/
		default:
			break;
	}
}

void sig_handler2(int signo, siginfo_t *info, void *context)
{
	int val = (int *)(info->si_value.sival_int);
	
	printf("sdjfdajfldjalfkjdslajflsajdlkf=%d", val);

	switch(val)
	{
		case 1:
			if(ch < MAXCH)
			{	
				ch++;
				printf("ch :%d\n", ch);
			}
			if(ch == MAXCH)
			{
				ch = MINCH;
				printf("ch :%d\n", ch);
			}
			break;
		case 2:
			if(ch > MINCH)
			{
				ch--;
				printf("ch :%d\n", ch);
			}
			if(ch == MINCH)
			{
				ch = MAXCH;   
				printf("ch :%d\n", ch);
			}
			break;
		case 3:
			if(vol < MAXVOL)
			{	
				vol++;
				printf("vol :%d\n", vol);
			}
			break;
		case 4:
			if(vol > MINVOL)
			{
				vol--;
				printf("vol :%d\n", vol);
			}
			break;
		default:
			break;
	}
}


int main()
{
	int dev, ret;
	struct sigaction sigact, sigact2;

	
	ch = 5;
	vol = 50;
	sigact.sa_sigaction = sig_handler;
	sigact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sigact, NULL);

	sigact2.sa_sigaction = sig_handler2;
	sigact2.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sigact2, NULL);

	dev = open("/dev/switch_dev", O_RDWR);
	
	tv_pid = getpid();
	printf("tv_pid = %d\n", tv_pid);
	ret = ioctl(dev, signal_ioctl1, &tv_pid);
	
	while(1);
	return 0;
}
