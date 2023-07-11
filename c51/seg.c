#include"seg.h"
#include<reg52.h>

unsigned char duan[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
unsigned char wei[]={0x01,0x02,0x04,0x08};

void delay(void)
{
	unsigned char j=165;
	while(j--);
}

void segx(unsigned int num)
{
	unsigned char i;
	for(i=0;i<4;i++)
	{
		P2=wei[i];
		switch(i)
		{
			case 0:P0=duan[num/1000];break;
			case 1:P0=duan[num/100%10];break;
			case 2:P0=duan[num/10%10];break;
			case 3:P0=duan[num%10];break;
		}
		delay();
		P0=0xff;
	}
}