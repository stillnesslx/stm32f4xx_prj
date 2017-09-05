//RuiXiaoliang
//20170831

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FAULT_H
#define __FAULT_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h"

#define SYSERR_LEFT_EXTREME 0x0001
#define SYSERR_RIGHT_EXTREME 0x0002
#define SYSERR_MODE0_NODATA 0X0004
#define SYSERR_WHEEL_LCOK 0x0008
#define SYSERR_MID_WHEEL 0x0010
#define SYSERR_PUSH_EXTREME 0x0020
#define SYSERR_DRAW_EXTREME 0x0040
#define SYSERR_BD_REF1 0x0080
#define SYSERR_ETH_UNCONNECT 0x0100
#define SYSERR_M0JC0 0X0200
#define SYSERR_M1JC1 0X0400
#define SYSERR_JC0 0X0800
#define SYSERR_5S_NODATA 0x1000
#define SYSERR_EEPROM 0x2000

extern uint32_t fault_code;


#ifdef __cplusplus
}
#endif

#endif /* __FAULT_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
