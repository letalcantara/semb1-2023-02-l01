#include <stdint.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define SRAM_START  0x20000000U                  /* Início da SRAM CORTEX-M */
#define SRAM_SIZE   (128U * 1024U)               /* Tamanho da SRAM STM32F411 128K */
#define SRAM_END    ((SRAM_START) + (SRAM_SIZE)) /* Final da SRAM STM32F411 */

#define STACK_START SRAM_END                     /* Início da Stack */

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

int main(void);

/* Protótipos de funções para as System Exceptions */

void reset_handler(void);
void nmi_handler(void) __attribute__((weak, alias("default_handler")));
void hardfault_handler(void) __attribute__((weak, alias("default_handler")));
void memmanage_handler(void) __attribute__((weak, alias("default_handler")));
void busfault_handler(void) __attribute__((weak, alias("default_handler")));
void usagefault_handler(void) __attribute__((weak, alias("default_handler")));
void svc_handler(void) __attribute__((weak, alias("default_handler")));
void debugmon_handler(void) __attribute__((weak, alias("default_handler")));
void pendsv_handler(void) __attribute__((weak, alias("default_handler")));
void systick_handler(void) __attribute__((weak, alias("default_handler")));

/* Protótipos para IRQ Handlers */
void wwdg_irq_handler(void) __attribute__((weak, alias("default_handler")));
void pvd_irq_handler(void) __attribute__((weak, alias("default_handler")));
void tamp_stamp_irq_handler(void) __attribute__((weak, alias("default_handler")));
void rtc_wkup_irq_handler(void) __attribute__((weak, alias("default_handler")));
void flash_irq_handler(void) __attribute__((weak, alias("default_handler")));
void rcc_irq_handler(void) __attribute__((weak, alias("default_handler")));
void exti0_irq_handler(void) __attribute__((weak, alias("default_handler")));
void exti1_irq_handler(void) __attribute__((weak, alias("default_handler")));
void exti2_irq_handler(void) __attribute__((weak, alias("default_handler")));
void exti3_irq_handler(void) __attribute__((weak, alias("default_handler")));
void exti4_irq_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream0_irq_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream1_irq_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream2_irq_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream3_irq_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream4_irq_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream5_irq_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream6_irq_handler(void) __attribute__((weak, alias("default_handler")));
void adc_irq_handler(void) __attribute__((weak, alias("default_handler")));
void exti9_5_irq_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_brk_tim9_irq_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_up_tim10_irq_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_trg_com_tim11_irq_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_cc_irq_handler(void) __attribute__((weak, alias("default_handler")));
void tim2_irq_handler(void) __attribute__((weak, alias("default_handler")));
void tim3_irq_handler(void) __attribute__((weak, alias("default_handler")));
void tim4_irq_handler(void) __attribute__((weak, alias("default_handler")));
void i2c1_ev_irq_handler(void) __attribute__((weak, alias("default_handler")));
void i2c1_er_irq_handler(void) __attribute__((weak, alias("default_handler")));
void i2c2_ev_irq_handler(void) __attribute__((weak, alias("default_handler")));
void i2c2_er_irq_handler(void) __attribute__((weak, alias("default_handler")));
void spi1_irq_handler(void) __attribute__((weak, alias("default_handler")));
void spi2_irq_handler(void) __attribute__((weak, alias("default_handler")));
void usart1_irq_handler(void) __attribute__((weak, alias("default_handler")));
void usart2_irq_handler(void) __attribute__((weak, alias("default_handler")));
void usart3_irq_handler(void) __attribute__((weak, alias("default_handler")));
void exti15_10_irq_handler(void) __attribute__((weak, alias("default_handler")));
void exti17_rtc_alarm_irq_handler(void) __attribute__((weak, alias("default_handler")));
void exti18_otg_fs_wkup_irq_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_stream7_irq_handler(void) __attribute__((weak, alias("default_handler")));
void sdio_irq_handler(void) __attribute__((weak, alias("default_handler")));
void tim5_irq_handler(void) __attribute__((weak, alias("default_handler")));
void spi3_irq_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream0_irq_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream1_irq_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream2_irq_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream3_irq_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream4_irq_handler(void) __attribute__((weak, alias("default_handler")));
void otg_fs_irq_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream5_irq_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream6_irq_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_stream7_irq_handler(void) __attribute__((weak, alias("default_handler")));
void usart6_irq_handler(void) __attribute__((weak, alias("default_handler")));
void i2c3_ev_irq_handler(void) __attribute__((weak, alias("default_handler")));
void i2c3_er_irq_handler(void) __attribute__((weak, alias("default_handler")));
void otg_hs_ep1_out_irq_handler(void) __attribute__((weak, alias("default_handler")));
void otg_hs_ep1_in_irq_handler(void) __attribute__((weak, alias("default_handler")));
void otg_hs_wkup_irq_handler(void) __attribute__((weak, alias("default_handler")));
void otg_hs_irq_handler(void) __attribute__((weak, alias("default_handler")));
void dcmi_irq_handler(void) __attribute__((weak, alias("default_handler")));
void cryp_irq_handler(void) __attribute__((weak, alias("default_handler")));
void hash_rng_irq_handler(void) __attribute__((weak, alias("default_handler")));
void fpu_irq_handler(void) __attribute__((weak, alias("default_handler")));

/****************************************************************************
 * External Data
 ****************************************************************************/

extern uint32_t _sdata;     /* Início da seção .data */
extern uint32_t _edata;     /* Fim da seção .data */
extern uint32_t _la_data;   /* Origem da seção .data na FLASH */

extern uint32_t _sbss;      /* Início da seção .bss */
extern uint32_t _ebss;      /* Fim da seção .bss */

/****************************************************************************
 * Private Data
 ****************************************************************************/

/* Tabela de Vetores de Interrupção */

uint32_t vectors[] __attribute__((section(".isr_vectors"))) =
{
  STACK_START,                            /* 0x0000 0000 */
  (uint32_t)reset_handler,                /* 0x0000 0004 */
  (uint32_t)nmi_handler,                  /* 0x0000 0008 */
  (uint32_t)hardfault_handler,            /* 0x0000 000c */
  (uint32_t)memmanage_handler,            /* 0x0000 0010 */
  (uint32_t)busfault_handler,             /* 0x0000 0014 */
  (uint32_t)usagefault_handler,           /* 0x0000 0018 */
  0,                                      /* 0x0000 001c */
  0,                                      /* 0x0000 0020 */
  0,                                      /* 0x0000 0024 */
  0,                                      /* 0x0000 0028 */
  (uint32_t)svc_handler,                  /* 0x0000 002c */
  (uint32_t)debugmon_handler,             /* 0x0000 0030 */
  0,                                      /* 0x0000 0034 */
  (uint32_t)pendsv_handler,               /* 0x0000 0038 */
  (uint32_t)systick_handler,              /* 0x0000 003c */
  /* Vetores de interrupção adicionais para STM32F411 */
  (uint32_t)wwdg_irq_handler,             /* 0x0000 0040 */
  (uint32_t)pvd_irq_handler,              /* 0x0000 0044 */
  (uint32_t)tamp_stamp_irq_handler,       /* 0x0000 0048 */
  (uint32_t)rtc_wkup_irq_handler,         /* 0x0000 004c */
  (uint32_t)flash_irq_handler,            /* 0x0000 0050 */
  (uint32_t)rcc_irq_handler,              /* 0x0000 0054 */
  (uint32_t)exti0_irq_handler,            /* 0x0000 0058 */
  (uint32_t)exti1_irq_handler,            /* 0x0000 005c */
  (uint32_t)exti2_irq_handler,            /* 0x0000 0060 */
  (uint32_t)exti3_irq_handler,            /* 0x0000 0064 */
  (uint32_t)exti4_irq_handler,            /* 0x0000 0068 */
  (uint32_t)dma1_stream0_irq_handler,     /* 0x0000 006c */
  (uint32_t)dma1_stream1_irq_handler,     /* 0x0000 0070 */
  (uint32_t)dma1_stream2_irq_handler,     /* 0x0000 0074 */
  (uint32_t)dma1_stream3_irq_handler,     /* 0x0000 0078 */
  (uint32_t)dma1_stream4_irq_handler,     /* 0x0000 007c */
  (uint32_t)dma1_stream5_irq_handler,     /* 0x0000 0080 */
  (uint32_t)dma1_stream6_irq_handler,     /* 0x0000 0084 */
  (uint32_t)adc_irq_handler,              /* 0x0000 0088 */
  (uint32_t)exti9_5_irq_handler,          /* 0x0000 008c */
  (uint32_t)tim1_brk_tim9_irq_handler,    /* 0x0000 0090 */
  (uint32_t)tim1_up_tim10_irq_handler,    /* 0x0000 0094 */
  (uint32_t)tim1_trg_com_tim11_irq_handler,/* 0x0000 0098 */
  (uint32_t)tim1_cc_irq_handler,          /* 0x0000 009c */
  (uint32_t)tim2_irq_handler,             /* 0x0000 00a0 */
  (uint32_t)tim3_irq_handler,             /* 0x0000 00a4 */
  (uint32_t)tim4_irq_handler,             /* 0x0000 00a8 */
  (uint32_t)i2c1_ev_irq_handler,          /* 0x0000 00ac */
  (uint32_t)i2c1_er_irq_handler,          /* 0x0000 00b0 */
  (uint32_t)i2c2_ev_irq_handler,          /* 0x0000 00b4 */
  (uint32_t)i2c2_er_irq_handler,          /* 0x0000 00b8 */
  (uint32_t)spi1_irq_handler,             /* 0x0000 00bc */
  (uint32_t)spi2_irq_handler,             /* 0x0000 00c0 */
  (uint32_t)usart1_irq_handler,           /* 0x0000 00c4 */
  (uint32_t)usart2_irq_handler,           /* 0x0000 00c8 */
  (uint32_t)usart3_irq_handler,           /* 0x0000 00cc */
  (uint32_t)exti15_10_irq_handler,        /* 0x0000 00d0 */
  (uint32_t)exti17_rtc_alarm_irq_handler, /* 0x0000 00d4 */
  (uint32_t)exti18_otg_fs_wkup_irq_handler,/* 0x0000 00d8 */
  (uint32_t)dma1_stream7_irq_handler,     /* 0x0000 00dc */
  (uint32_t)sdio_irq_handler,             /* 0x0000 00e0 */
  (uint32_t)tim5_irq_handler,             /* 0x0000 00e4 */
  (uint32_t)spi3_irq_handler,             /* 0x0000 00e8 */
  (uint32_t)dma2_stream0_irq_handler,     /* 0x0000 00ec */
  (uint32_t)dma2_stream1
