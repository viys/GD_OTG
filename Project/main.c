#include "gd32f10x.h"
#include "systick.h"
#include <stdio.h>

int main(void)
{
    /* configure systick */
    systick_config();
    
    /* print out the clock frequency of system, AHB, APB1 and APB2 */
    printf("\r\nCK_SYS is %d", rcu_clock_freq_get(CK_SYS));
    printf("\r\nCK_AHB is %d", rcu_clock_freq_get(CK_AHB));
    printf("\r\nCK_APB1 is %d", rcu_clock_freq_get(CK_APB1));
    printf("\r\nCK_APB2 is %d", rcu_clock_freq_get(CK_APB2));

    while(1){
    }
}

/* retarget the C library printf function to the USART */
//int fputc(int ch, FILE *f)
//{
//    usart_data_transmit(EVAL_COM0, (uint8_t)ch);
//    while(RESET == usart_flag_get(EVAL_COM0, USART_FLAG_TBE));

//    return ch;
//}
