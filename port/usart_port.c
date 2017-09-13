//RuiXiaoliang
//20170906
#include "usart_port.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

struct usart_buffer usart_buf = {0,0,{0}};

void STM_EVAL_COMInit(USART_InitTypeDef* USART_InitStruct)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  /* Enable GPIO clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

  //if (COM == COM1)
  //{
    /* Enable UART clock */
    RCC_APB1PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
  //}

  /* Connect PXx to USARTx_Tx*/
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);

  /* Connect PXx to USARTx_Rx*/
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);

  /* Configure USART Tx as alternate function  */
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* Configure USART Rx as alternate function  */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* USART configuration */
  USART_Init(USART1, USART_InitStruct);
    
  /* Enable USART */
  USART_Cmd(USART1, ENABLE);
}
void USART_Config(void)
{
  USART_InitTypeDef USART_InitStructure;
  
/* USARTx configuration ------------------------------------------------------*/
  /* USARTx configured as follows:
        - BaudRate = 9600 baud  
        - Word Length = 8 Bits
        - Two Stop Bit
        - Odd parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  */
  USART_InitStructure.USART_BaudRate = 9600;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_2;
  USART_InitStructure.USART_Parity = USART_Parity_Odd;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

  STM_EVAL_COMInit(&USART_InitStructure);
}

void usart1_receive(void)
{
    char data;
    if(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == SET)
    {
        data = USART_ReceiveData(USART1);
        if('\n' != data)
        {
            usart_buf.buf[usart_buf.cnt++] = data;
        }
        else
        {
            usart_buf.len = usart_buf.cnt;
            usart_buf.cnt = 0;
        }
    }
}
//end of file
