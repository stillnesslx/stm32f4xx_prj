//RuiXiaoliang
//20170831

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DELAY_H
#define __DELAY_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h"


extern void delay_ms(uint16_t ms);
extern void delay_us(uint32_t us);



#ifdef __cplusplus
}
#endif

#endif /* __DELAY_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
