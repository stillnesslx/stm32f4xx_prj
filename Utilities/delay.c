//RuiXiaoliang
//20170901

#include "delay.h"

void delay_us(uint32_t us)
{
	uint16_t mf = 168;
	while(us > 0)
	{
		--us;
		while(--mf);
	}
}
void delay_ms(uint16_t ms)
{
	uint32_t mf = 168000;
	while(ms-- > 0)
	{
		while(--mf);
	}
}
//end of file
