#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


//#include <linux/kernel.h>
//#include <linux/cdev.h>
//#include <linux/fs.h>
//#include <asm/uaccess.h>
//#include <linux/device.h>
//#include <asm/uaccess.h> //for solving warning of imp declar of printk

int main(int argc, char *argv[])
{
	char buff[4];
	printf("Hello World, I'm game!\n");
	printf("Im going to try to read the buttons state:");
	int fd = open("/dev/gamePad",O_RDONLY);
	if(fd < 0){
		printf("error opening the device!");
	}
	while(1){
		read(fd,buff,4);
		printf(" Bufer main read is: %c %c\n",buff[2],buff[3]);
	}
	close(fd);
	exit(EXIT_SUCCESS);
}
