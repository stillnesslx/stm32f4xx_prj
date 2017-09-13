//RuiXiaoliang
//20170908

#include "cal_lms5xx.h"
#include "algorithm.h"
#include "string.h"
#include "triangle.h"
//#include "stm32f4xx_conf.h"

#define SENSOR_STEP_INIT 5000
#define BARRIER_VER_LEN_MIN 1000
#define BARRIER_VER_LEN_MAX 5000


struct lms5xx_data sensor_data;

const unsigned char frame_head[] = {0x02,0x02,0x02,0x02,0x00,0x00,0x02,0x3b,0x73,0x52,0x41,0x20,0x4c,0x4d,0x44,\
									0x73,0x63,0x61,0x6e,0x64,0x61,0x74,0x61,0x20,0x00,0x00,0x00,0x01};

const uint8_t ascii_poll_one_cmd[20]={0x02,0x73,0x52,0x4E,0x20,0x4c,0x4D,0x44,0x73,0x63,0x61,0x6E,0x64,0x61,\
										0x74,0x61,0x03};
const uint8_t binary_poll_one_cmd[24] = {0x02,0x02,0x02,0x02,0x00,0x00,0x00,0x0F,0x73,0x52,0x4E,0x20,0x4C,0x4D,\
										0x44,0x73,0x63,0x61,0x6E,0x64,0x61,0x74,0x61,0x05};
const uint8_t ascii_permanently_cmd[] = {0x02,0x73,0x45,0x4E,0x20,0x4C,0x4D,0x44,0x73,0x63,0x61,0x6E,0x64,0x61,\
										0x74,0x61,0x20,0x31,0x03};
const uint8_t binary_permanently_cmd[] = {0x02,0x02,0x02,0x02,0x00,0x00,0x00,0x11,0x73,0x45,0x4E,0x20,0x4C,0x4D,\
										0x44,0x73,0x63,0x61,0x6E,0x64,0x61,0x74,0x61,0x20,0x01,0x33};

void cal_par_init(void)
{
	memset((void *)&sensor_data,0,sizeof(sensor_data));
	sensor_data.bus_cone_min_dist = BUS_CONE_MIN_DIST_INIT;
	sensor_data.bus_cone_max_dist = BUS_CONE_MAX_DIST_INIT;
	sensor_data.sensor_step = SENSOR_STEP_INIT;
	sensor_data.bus_cone_vary_threshold = DIST_VARY_THRESHOLD_INIT;
}

int cal_len_of_vertical_line(struct lms5xx_data *cone_buf)
{
	uint16_t i;
	float theta;
	if(cone_buf->len < 2)
	{
		return cone_buf->len;
	}
	for(i=0;i<(cone_buf->len+1)/2;i++)
	{
		theta = int_abs(cone_buf->buf[i].pos - cone_buf->buf[cone_buf->len/2+i].pos) * cone_buf->sensor_step  / 10000.0f * PI / 180.0f;
		cone_buf->vertical[i] = length_of_altitude(cone_buf->buf[i].dist+CONE_RADIUS,\
								cone_buf->buf[cone_buf->len/2+i].dist+CONE_RADIUS,theta);
	}
	cone_buf->cnt = 0;
	cone_buf->last_amount = cone_buf->len;
	cone_buf->len = 0;
	return cone_buf->len;
}
//void sensor_data_pre_cut(int32_t *buf, uint16_t len, struct lms5xx_data *cone_buf)
//{
	
//}
uint16_t search_barrier(uint16_t *buf, uint16_t len, struct lms5xx_data *cone_buf)
{
	uint16_t i,j;
	for(i=1;i<len;i++)
	{
		if((buf[i] > cone_buf->bus_cone_min_dist) && (buf[i] < cone_buf->bus_cone_max_dist) && \
			((buf[i-1] > buf[i]) && ((buf[i-1]-buf[i]) > cone_buf->bus_cone_vary_threshold)))
		{
			cone_buf->buf[cone_buf->cnt].dist = buf[i];
			cone_buf->buf[cone_buf->cnt].pos = i;
			for(j=i+1;j<MIN_IN_TWO(len,i+CONE_DIST_DATA_AMOUNT_MAX);j++)
			{
				if((buf[j] > buf[j-1]) && ((buf[j]-buf[j-1]) <= cone_buf->bus_cone_vary_threshold))
				{
					if(cone_buf->buf[cone_buf->cnt].dist > buf[j])
					{
						cone_buf->buf[cone_buf->cnt].dist = buf[j];
						cone_buf->buf[cone_buf->cnt].pos = j;
					}
				}
				else //if((buf[j+1]-buf[j]) > DIST_VARY_THRESHOLD)
				{
					//cone_buf->buf[cone_buf->cnt].start = i;
					//cone_buf->buf[cone_buf->cnt].len = j-i+1;
					//memcpy(cone_buf->buf[cone_buf->cnt].buf,&buf[i],j-i+1);
					cone_buf->cnt++;
					cone_buf->len++;
					if(cone_buf->cnt >= CONE_AMOUNT_MAX)
					{
						cone_buf->cnt = 0;
					}
					if(cone_buf->len >= CONE_AMOUNT_MAX)
					{
						cone_buf->len = CONE_AMOUNT_MAX;
					}
					i = j;
					break;
				}
			}
		}
		//cone_buf->len = cone_buf->cnt;
		//cone_buf->cnt = 0;
	}
	return cone_buf->len;
}
int deal_tcp_frame(struct fifo_buffer *fifo)
{
	if(fifo->wr != fifo->rd)
	{
		if(0 == memcmp(fifo->buf_ptr+fifo->rd*fifo->byte_sizes,frame_head,sizeof(frame_head)))
		{
			uint16_t len;
			len = (uint16_t)*(fifo->buf_ptr+fifo->rd*fifo->byte_sizes+POS_AMOUNT_DATA);
			search_barrier((uint16_t *)(fifo->buf_ptr+fifo->rd*fifo->byte_sizes+POS_DATA),len,&sensor_data);
			cal_len_of_vertical_line(&sensor_data);
			fifo->rd++;
			if(fifo->rd >= fifo->buf_size)
			{
				fifo->rd = 0;
			}
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 1;
	}
}
int num_ascii_to_int(char c)
{
	int num;
	//assert_param(((c > 0x40) && (c < 0x47)) || ((c > 0x2f) && (c < 0x3a)));
	if((c >= '0') && (c <= '9'))
	{
		num = c -  '0';		
	}
	else if((c >= 'A') && (c <= 'Z'))
	{
		num = c - 'A' + 10;
	}
	else if((c >= 'a') && (c <= 'z'))
	{
		num = c - 'a' + 10;
	}
	else
	{
		num = -1;
	}
	return num;
}
//end of file
