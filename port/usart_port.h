//RuiXiaoliang
//20170831

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_PORT_H
#define __USART_PORT_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h"

#define TEST_BUF_LEN 256
struct usart_buffer
{
    unsigned short int len;
    unsigned short int cnt;
    char buf[TEST_BUF_LEN];
};
extern struct usart_buffer usart_buf;
extern void USART_Config(void);
extern void usart1_receive(void);


#ifdef __cplusplus
}
#endif

#endif /* __USART_PORT_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
