//RuiXiaoliang
//20170912



#include "algorithm.h"

int32_t search_min_int(int32_t *buf, uint16_t len)
{
	int i;
	int32_t min = buf[0];
	for(i=1;i<len;i++)
	{
		if(min > buf[i])
		{
			min = buf[i];
		}
	}
	return min;
}
unsigned int int_abs(int a)
{
	return a > 0 ? a : -a;
}

//end of file
