# NUCLEO-F767ZI_CommandLine

## Development Board - Notes
    
    Using STMicro NUCLEO-F767ZI
    HSE 8MHz crystal
    SYSCLK: 216MHz
    
    
## Middleware / Software Packs Installed
    
    FreeRTOS
      USE_NEWLIB_REENTRANT            Enabled
      GENERATE_RUN_TIME_STATS         Enabled
      USE_TRACE_FACILITY              Enabled
      USE_STATS_FORMATTING_FUNCTIONS  Enabled

    System Core -> SYS -> Timebase Source: TIM14

## 32-bit microsecond Timer
    
    TIM5 - (108-1) prescaler to create 1us increments
    
## UART3
    
    UART3, connected though STLink, is configured to use a circular DMA receive buffer
    Baud: 115200

## Command Line
    
    int __io_getchar(void);   // main.c
    int __io_putchar(int ch); // main.c
    
    
## General Notes
    
    Initially, LWIP was enabled, but lwip_int() doesn't return - Disabled LWIP
    
    Command Line, currently functioning within "defaultTask", requires a larger stack.
      Allow 512 bytes for stack space