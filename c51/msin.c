#include<reg52.h>
#include"seg.h"

unsigned int cnt;
unsigned char x;
unsigned char keynum=0;
unsigned char maxlight=0;

void time0init(void)
{
	TMOD &= 0XF0;
	TMOD |= 0X01;
	TL0 = 0XC2;
	TH0 = 0X3C;
	ET0 = 1;
	EA = 1;
	TF0 = 0;
	TR0 = 1;
}

void count1init(void)
{
	TMOD &= 0X0F;
	TMOD |= 0X50;
	TL1 = 0;
	TH1 = 0;
	TF1 = 0;
	TR1 = 1;
}

void interinit(void)
{
	IT0 = 1;
	EX0 = 1;
}



void main()
{
	interinit();
	time0init();
	count1init();
	while(1)
	{
		segx(cnt);
	}
}

void time0run() interrupt 1
{
	TL0 = 0XC2;
	TH0 = 0X3C;
	x++;
	if(x>=20)
	{
		TR1 = 0;
		x = 0;
		cnt = TH1*256+TL0;
		TH1 = 0;
		TL1 = 0;
		TR1 = 1;
	}

}

void inter0() interrupt 0
{
	keynum++;
	switch(keynum)
	{
		case 1:maxlight=25;break;
		case 2:maxlight=50;break;
		case 3:maxlight=75;break;
		case 4:maxlight=100;break;
		case 5:maxlight=0;keynum=0;break;
	}
}
