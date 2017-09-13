//RuiXiaoliang
//20170831

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ALGORITHM_H
#define __ALGORITHM_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stdint.h"

#define PI 3.1415926f

#define ABS_CAL(a) ((a)>0?(a):(-(a)))
#define MIN_IN_TWO(a,b) ((a)<(b)?(a):(b))

struct fifo_buffer
{
    uint8_t  *buf_ptr;
	uint16_t  byte_wr;
	uint16_t byte_len;
	uint16_t byte_sizes;
    volatile uint16_t rd;
    volatile uint16_t wr;
    uint16_t buf_size;
};

extern unsigned int int_abs(int a);
extern int32_t search_min_int(int32_t *buf, uint16_t len);


#ifdef __cplusplus
}
#endif

#endif /* __ALGORITHM_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
