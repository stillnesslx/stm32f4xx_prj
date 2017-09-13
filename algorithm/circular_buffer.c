/**
  ******************************************************************************
  * @file    circular_buffer.c
  * @author  RuiXiaoliang
  * @version V1.0.0
  * @date    11-February-2014
  * @brief   circular array buffer:�����㷨����ҪԤ�ȶ����ѭ������
  ******************************************************************************
  * @attention
  ******************************************************************************
**/
#include "string.h"
#include "circular_buffer.h"


//a array of struct void type must be defined before,and the lenght of it is another
//function parameter u16 size which means how many elements in array.

void cir_buf_init(struct circular_buffer *cb, void *array, SIZE_TYPE size)
{
    cb->size = size;
    cb->start = 0;
    cb->count = 0;
    cb->elem = array;
}

FLAG_TYPE cir_buf_is_full(struct circular_buffer *cb)
{
    return cb->count == cb->size;
}

FLAG_TYPE cir_buf_is_empty(struct circular_buffer *cb)
{
    return cb->count == 0;
}
//Write an element, overwriting oldest element if buffer is full. App cbn
//choose to avoid the overwrite by checking cbIsFull().
//size means how many chars(bytes) in one element.
void cir_buf_enter(struct circular_buffer *cb, void *elem, SIZE_TYPE size)
{
    SIZE_TYPE end = (cb->start + cb->count) % cb->size;
    memcpy(((char*)cb->elem + end * size),(char*)elem,size);
    if(cb->count == cb->size)
    {
        cb->start = (cb->start + 1) % cb->size;   //full overwrite
    }
    else
    {
        ++cb->count;
    }
}
//Read oldest element. App must ensure !cbIsEmpty() first.
//size means how many chars(bytes) in one element.
void cir_buf_read(struct circular_buffer *cb, void *elem, SIZE_TYPE size)
{
    memcpy((char*)elem,((char*)cb->elem + cb->start * size), size);
    cb->start = (cb->start + 1) % cb->size;
    --cb->count;
}
//read oldest element addr.App must ensure !cbIsEmpty() first.
//size means how many chars(bytes) in one element.
//���ַ�ʽ����ֻ���ָ�룬��Ȼ����ֱ�Ӳ������ݣ����������ݿ���������Ҳ������Ϊû�п������ݣ��������ݵ�ʱ���п��ܱ��µ����ݸ��ģ����´���
//����ܱ�֤�������ݹ��������ݲ��ᱻ�µ����ݸ��ǣ������
//void * cir_buf_read_pointer(struct circular_buffer *cb, void *elem, SIZE_TYPE size)
//{
//    void *tmp;
//    tmp = (void*)((char*)cb->elem + cb->start * size);
//    //memcpy((char*)elem,(char*)(cb->elem + cb->start * size), size);
//    cb->start = (cb->start + 1) % cb->size;
//    --cb->count;
//    return tmp;
//}

//get number of elements
SIZE_TYPE cir_buf_len(struct circular_buffer *cb)
{
    return cb->count;
}
//delete elements
unsigned int cir_buf_delete_element(struct circular_buffer *cb, SIZE_TYPE len)
{
    if(cb->count > len)
    {
        cb->start = (cb->start + len) % cb->size;
        cb->count -= len;
        return len;
    }
    else
    {
        SIZE_TYPE tmp;
        tmp = cb->count;
        cb->start = (cb->start + cb->count) % cb->size;
        cb->count = 0;
        return tmp;
    }
}
//extern funtions
//Read oldest elements. App must ensure cb_len > len first.
//size: how many chars(bytes) in one element.
//len: how many elements to be read
unsigned int cir_buf_ex_read(struct circular_buffer *cb, void *elem_buf, SIZE_TYPE size, SIZE_TYPE len)
{
    if(cb->count >= len)
    {
        SIZE_TYPE i;
        for(i=0;i<len;i++)
        {
            cir_buf_read(cb, (char*)elem_buf + i * size, size);
        }
        return len;
    }
    else
    {
        SIZE_TYPE i;
        SIZE_TYPE tmp;
        tmp = cb->count;
        for(i=0;i<tmp;i++)
        {
            cir_buf_read(cb, (char*)elem_buf + i * size, size);
        }
        return tmp;
    }
}
//end of file


