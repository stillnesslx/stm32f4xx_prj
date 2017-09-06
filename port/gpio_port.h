//RuiXiaoliang
//20170831

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_PORT_H
#define __GPIO_PORT_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h"

#define LED6_ON  do{GPIO_WriteBit(GPIOA,GPIO_Pin_12, Bit_SET)}while(0)
#define LED6_OFF do{GPIO_WriteBit(GPIOA,GPIO_Pin_12, Bit_RESET)}while(0)
#define LED2_ON  do{GPIO_WriteBit(GPIOG,GPIO_Pin_6, Bit_SET)}while(0)
#define LED2_OFF do{GPIO_WriteBit(GPIOG,GPIO_Pin_6, Bit_RESET)}while(0)
#define LED3_ON  do{GPIO_WriteBit(GPIOG,GPIO_Pin_7, Bit_SET)}while(0)
#define LED3_OFF do{GPIO_WriteBit(GPIOG,GPIO_Pin_7, Bit_RESET)}while(0)
#define LED5_ON  do{GPIO_WriteBit(GPIOG,GPIO_Pin_8, Bit_SET)}while(0)
#define LED5_OFF do{GPIO_WriteBit(GPIOG,GPIO_Pin_8, Bit_RESET)}while(0)

#define FAULT_ERR do{GPIO_WriteBit(GPIOI,GPIO_Pin_2,Bit_RESET);}while(0)  //故障停车 为0
#define FAULT_OK  do{GPIO_WriteBit(GPIOI,GPIO_Pin_2,Bit_SET);}while(0)  //故障停车 为0

#define DRAW_WHEEL do{GPIO_WriteBit(GPIOI,GPIO_Pin_1, Bit_SET);GPIO_WriteBit(GPIOI,GPIO_Pin_0, Bit_RESET);}while(0)
#define PUSH_WHEEL do{GPIO_WriteBit(GPIOI,GPIO_Pin_1, Bit_RESET);GPIO_WriteBit(GPIOI,GPIO_Pin_0, Bit_SET);}while(0)
#define STOP_WHEEL do{GPIO_WriteBit(GPIOI,GPIO_Pin_1, Bit_RESET);GPIO_WriteBit(GPIOI,GPIO_Pin_0, Bit_RESET);}while(0)

extern void GPIO_In_Config(void);
extern void GPIO_Out_Config(void);

#ifdef __cplusplus
}
#endif

#endif /* __GPIO_PORT_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
