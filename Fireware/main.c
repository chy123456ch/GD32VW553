#include "gd32vw55x.h"
#include "systick.h"
#include <stdio.h>
#include "Bsp_Usart.h"

int main(void)
{
    // 初始化系统滴答定时器
    systick_config();
    Bsp_Usart_Init(USART0,115200,8,1,0);
    // 开启GPIOC时钟
    RCU_AHB1EN |= (1 << 2);

    // 配置引脚为输出模式
    GPIO_CTL(GPIOC) &= ~(0x03 << (26));
    GPIO_CTL(GPIOC)  |= (0x01 << (26));

    // 配置引脚为浮空模式，无上拉下拉
    GPIO_PUD(GPIOC) &=  ~(0x03 << (2*13));
    GPIO_PUD(GPIOC) |=  (0x00 << (2*13));

    // 配置为推挽输出
    GPIO_OMODE(GPIOC) &= ~(0x01 << 13);

    // 配置引脚速度
    GPIO_OSPD(GPIOC) &=  ~(0x03 << (2 * 13));
    GPIO_OSPD(GPIOC) |=  (0x02 << (2 * 13));

    //输出高电平，点亮LED
    
    while(1)
    {

    }
}


void eclic_mtip_handler(void)
{
  static uint32_t sys_tick = 0;
  sys_tick++;
  if(sys_tick >= 1000)
  {
      gpio_bit_toggle(GPIOC,GPIO_PIN_13);
      sys_tick = 0;
  }
}