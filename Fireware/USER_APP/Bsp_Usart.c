
#include "Bsp_Usart.h"


/*
	PB15 USART0_TX
	PA8  USART0_RX

*/
void Bsp_Usart_Init(uint8_t Usart_Chn,uint32_t baudrates,uint8_t databits,uint8_t stopbits,uint8_t paraitys)
{

  gpio_mode_set(GPIOA,GPIO_MODE_AF,GPIO_PUPD_PULLUP,);

  usart_clock_enable(Usart_Chn);
  usart_baudrate_set(Usart_Chn,baudrates);
  usart_parity_config(Usart_Chn,paraitys);
  usart_word_length_set(Usart_Chn,databits);
  usart_stop_bit_set(Usart_Chn,stopbits);
  usart_enable(Usart_Chn);
  usart_transmit_config(Usart_Chn,USART_TRANSMIT_ENABLE);
  usart_receive_config(Usart_Chn,USART_RECEIVE_ENABLE);
  usart_interrupt_enable(Usart_Chn,USART_INT_RBNE);
}





