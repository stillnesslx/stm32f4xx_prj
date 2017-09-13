//RuiXiaoliang
//20170831

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TRIANGLE_H
#define __TRIANGLE_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stdint.h"
//#define HERONS_FORMULA(a,b,c) do{float s = (((a)+(b)+(c))/2.0f);}

#define LAW_OF_COSINES_c2(a,b,C) ((a)*(a)+(b)*(b)-2*(a)*(b)*cos(C))
#define LAW_OF_COSINES_COSC(a,b,c) (((a)*(a)+(b)*(b)-(c)*(c))/2/a/b)

extern uint32_t length_of_altitude(uint32_t a,uint32_t b,float angle);


#ifdef __cplusplus
}
#endif

#endif /* __TRIANGLE_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
