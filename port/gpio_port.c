/**
  ******************************************************************************
  * @file    stm324xg_gpio.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    30-September-2011
  * @brief   This file provides
  *            - set of firmware functions to manage gpio in /out
  *            -by mdf.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2015 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 
  
/* Includes ------------------------------------------------------------------*/
//#include "stm324xg_eval.h"
#include "gpio_port.h"
//#include "stm32f4xx_sdio.h"
//#include "stm32f4xx_dma.h"
#include "stm32f4xx_i2c.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
/**************************************************************************************************************/
/**
  * @brief  Configures  GPIO OUT--------PP.
  * @param  GPIOA   
  *     @arg GPIO_Pin_12: ͣ��ָʾ��LED4
	* @param  GPIOG   
  *     @arg GPIO_Pin_6: ǰ��ָʾ��LED1
  *     @arg GPIO_Pin_7: ����ָʾ��LED2
  *     @arg GPIO_Pin_8: �궨ָʾ��LED3
	* @param  GPIOI  
  *     @arg GPIO_Pin_0: push        //ԭ�����������Ϊ���ź� 
  *     @arg GPIO_Pin_1: draw    //ԭ���źţ���Ϊ���ź� 
  *     @arg GPIO_Pin_2:          //ԭΪ���ź���Ϊ�����ź�
  *     
  * @retval None
  **************************************************************************************************************/

void GPIO_Out_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* Enable GPIOs clocks */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB |
					 RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOI |
					 RCC_AHB1Periph_GPIOG | RCC_AHB1Periph_GPIOH |
					 RCC_AHB1Periph_GPIOF, ENABLE);

	/* Enable SYSCFG clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);  

	/* Configure OUT (PI0~PI2) */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOI, &GPIO_InitStructure);

	//	  /* Configure OUT (PH14~PH15) */
	//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_15;
	//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	//  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	//  GPIO_Init(GPIOH, &GPIO_InitStructure);

	  /* Configure OUT (PA12) */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	  /* Configure OUT (PG6~PG8) */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOG, &GPIO_InitStructure);
	
}



/**************************************************************************************************************/
/**
  * @brief  Configures  GPIO IN---.
  * @param  GPIOH   
  *     @arg GPIO_Pin_8:����ѡ��
  * @param  GPIOB   
  *     @arg GPIO_Pin_5: ����
  *     @arg GPIO_Pin_6: ����
  *     @arg GPIO_Pin_7: ����
  * @param  GPIOH   
  *     @arg GPIO_Pin_8: ����ѡ��IN1  ��Ϊ����ǰ���ź�
  *     @arg GPIO_Pin_9: ����ѡ��IN2   ��Ϊ���Ժ����ź�
  *     @arg GPIO_Pin_10: ����ѡ��IN3   ��Ϊ���Ա궨�ź�
  *     @arg GPIO_Pin_11: ����ѡ��IN4   ��Ϊ���Ըߵ����ź�
  * @param  GPIOI
  *     @arg GPIO_Pin_3: Կ�׿���
  *     @arg GPIO_Pin_4: ԭ�궨�źţ���Ϊ�����������ź�
  *     @arg GPIO_Pin_5: Reserved
  *     @arg GPIO_Pin_6: Reserved
  *     
  * @retval None
  **************************************************************************************************************/
void GPIO_In_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* Enable GPIOs clocks */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB |
					 RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOI |
					 RCC_AHB1Periph_GPIOG | RCC_AHB1Periph_GPIOH |
					 RCC_AHB1Periph_GPIOF, ENABLE);

	/* Enable SYSCFG clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);  

	/* Configure OUT (PI3~PI6) */
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6|GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOI, &GPIO_InitStructure);

	/* Configure OUT (PH8~PH9) */
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOH, &GPIO_InitStructure);

	//	/* Configure OUT (PF9) */
	//		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_9;
	//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	//  GPIO_Init(GPIOF, &GPIO_InitStructure);
	//		

	//		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_2;
	//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	//  GPIO_Init(GPIOC, &GPIO_InitStructure);

}

//end of file



