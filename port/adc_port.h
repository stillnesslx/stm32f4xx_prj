//RuiXiaoliang
//20170831

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ADC_PORT_H
#define __ADC_PORT_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h"

#define ADCx                     ADC3
#define ADC_CHANNEL              ADC_Channel_7
#define ADCx_CLK                 RCC_APB2Periph_ADC3
#define ADCx_CHANNEL_GPIO_CLK    RCC_AHB1Periph_GPIOF
#define GPIO_PIN                 GPIO_Pin_9
#define GPIO_PORT                GPIOF
#define DMA_CHANNELx             DMA_Channel_2
#define DMA_STREAMx              DMA2_Stream0
#define ADCx_DR_ADDRESS          ((uint32_t)0x4001224C)

extern void ADC_Config(void);


#ifdef __cplusplus
}
#endif

#endif /* __ADC_PORT_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
