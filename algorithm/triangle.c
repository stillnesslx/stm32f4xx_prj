//RuiXiaoliang
//20170906
//distance unit:mm

#include "triangle.h"
#include "math.h"

float herons_formular(float a, float b, float c)
{
	float s = (a + b + c) / 2.0f;
	return sqrtf(s*(s-a)*(s-b)*(s-c));
}

uint32_t length_of_altitude(uint32_t a,uint32_t b,float angle)
{
	uint32_t c;
	float area;
	c = sqrtf(LAW_OF_COSINES_c2(a,b,angle));
	area = a*b*sin(angle);
	return 2*area/c;
}

//end of file
