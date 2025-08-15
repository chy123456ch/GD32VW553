#ifndef __BSP_USART_H__
#define __BSP_USART_H__

#include "gd32vw55x.h"
#include "gd32vw55x_usart.h"


void Bsp_Usart_Init(uint8_t Usart_Chn,uint32_t baudrates,uint8_t databits,uint8_t stopbits,uint8_t paraitys);



#endif
