//RuiXiaoliang
//20170908

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CAL_LMS5XX_H
#define __CAL_LMS5XX_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx.h"
#include "tcp_echoclient.h"
	 
#define CONE_DIAMETER 		200U //20cm
#define CONE_RADIUS (CONE_DIAMETER/2)
#define BUS_CONE_MIN_DIST_INIT 1000U //3m
#define BUS_CONE_MAX_DIST_INIT 3000U //3m
#define BUS_CONE_DIST_MAX 6000U //6m
#define BUS_CONE_DIST_MIN  1000U //1m

#define DIST_VARY_THRESHOLD_INIT (CONE_DIAMETER)

#define POS_AMOUNT_DATA 84
#define POS_DATA 86

#define CONE_AMOUNT_MAX 20
#define CONE_DIST_DATA_AMOUNT_MAX 32
struct one_cone_dist_data
{
	//uint16_t start;
	//uint16_t len;
	int16_t pos;
	uint32_t dist;
	//int32_t buf[CONE_DIST_DATA_AMOUNT_MAX];
};
struct lms5xx_data
{
	uint16_t sensor_step;
	uint16_t bus_cone_min_dist;
	uint16_t bus_cone_max_dist;
	uint16_t bus_cone_vary_threshold;
	uint16_t last_amount;
	uint16_t cnt;
	uint16_t len;
	uint16_t vertical[CONE_AMOUNT_MAX/2];
	struct one_cone_dist_data buf[CONE_AMOUNT_MAX];
};
extern const uint8_t ascii_poll_one_cmd[20];
extern const uint8_t binary_poll_one_cmd[24];
extern const uint8_t ascii_permanently_cmd[];
extern const uint8_t binary_permanently_cmd[];

extern void cal_par_init(void);
extern int deal_tcp_frame(struct fifo_buffer *fifo);

#ifdef __cplusplus
}
#endif

#endif /* __CAL_LMS5XX_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
