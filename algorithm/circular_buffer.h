/**
  ******************************************************************************
  * @file    circular_buffer.h
  * @author  RuiXiaoliang
  * @version V1.0.0
  * @date    11-February-2014
  * @brief   circular array buffer
  * @record  20141218:add typedef SIZE_TYPE FLAG_TYPE
  ******************************************************************************
  * @attention
  ******************************************************************************
**//* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CIRCULAR_BUFFER_H
#define __CIRCULAR_BUFFER_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

//#define ELEM_SIZE       ((u16)10)
//#define ARRAY_SIZE      (ELEM_SIZE + 1)
typedef unsigned short int SIZE_TYPE;
typedef unsigned char FLAG_TYPE;

struct circular_buffer
{
    SIZE_TYPE size;                   //maximum number of elements
    SIZE_TYPE start;                  //index of oldest element
    SIZE_TYPE count;                    //index at which to write new element
    unsigned char *elem;  //array of elements
};
extern void cir_buf_init(struct circular_buffer *cb, void *array, SIZE_TYPE size);
extern void cir_buf_enter(struct circular_buffer *cb, void *elem,SIZE_TYPE size);
extern void cir_buf_read(struct circular_buffer *cb, void *elem,SIZE_TYPE size);
extern SIZE_TYPE cir_buf_len(struct circular_buffer *cb);
extern FLAG_TYPE cir_buf_is_full(struct circular_buffer *cb);
extern FLAG_TYPE cir_buf_is_empty(struct circular_buffer *cb);
extern unsigned int cir_buf_delete_element(struct circular_buffer *cb, SIZE_TYPE len);

extern unsigned int cir_buf_ex_read(struct circular_buffer *cb, void *elem_buf, SIZE_TYPE size, SIZE_TYPE len);
#ifdef __cplusplus
}
#endif

#endif /*__CIRCULAR_BUFFER_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT  *****END OF FILE****/
