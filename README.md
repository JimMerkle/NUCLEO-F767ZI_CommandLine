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
    
## FreeRTOS Command Line 'Commands'
    
    '''>oslist'''
        Task     Status  Priority  Stack  Task#
    defaultTask     X       3       336     1
    IDLE            R       0       104     2
    
    Note: "Stack" is unused stack space, expressed as a quantity of 32-bit words
    
    '''>osinfo'''
        Task        RunTime       Percent
    defaultTask     7129218         1%
    IDLE            609988207               98%
    
    After adding a 200 byte buffer (from stack space):
    '''>oslist'''
        Task     Status  Priority  Stack  Task#
    defaultTask     X       3       284     1
    IDLE            R       0       104     2

## General Notes
    
    Initially, LWIP was enabled, but lwip_int() doesn't return - Removed LWIP
    
    Command Line, currently functioning within "defaultTask", requires a larger stack.
      Allow 512 bytes for stack space