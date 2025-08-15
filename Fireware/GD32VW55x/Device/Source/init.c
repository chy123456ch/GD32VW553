#include "gd32vw55x.h"

extern void nmi_handler(unsigned long mcause, unsigned long sp);
extern void Exception_Init(void);
extern void Exception_Register_EXC(uint32_t EXCn, unsigned long exc_handler);

/**
 * \brief early init function before main
 * \details
 * This function is executed right before main function.
 * For RISC-V gnu toolchain, _init function might not be called
 * by __libc_init_array function, so we defined a new function
 * to do initialization
 */
void _premain_init(void)
{
    /* TODO: Add your own initialization code here, called before main */
}

/**
 * \brief finish function after main
 * \param [in]  status     status code return from main
 * \details
 * This function is executed right after main function.
 * For RISC-V gnu toolchain, _fini function might not be called
 * by __libc_fini_array function, so we defined a new function
 * to do initialization
 */
void _postmain_fini(int status)
{
    /* TODO: Add your own finishing code here, called after main */
}

/**
 * \brief _init function called in __libc_init_array()
 * \details
 * This `__libc_init_array()` function is called during startup code,
 * user need to implement this function, otherwise when link it will
 * error init.c:(.text.__libc_init_array+0x26): undefined reference to `_init'
 * \note
 * Please use \ref _premain_init function now
 */
void _init(void)
{
    /* Don't put any code here, please use _premain_init now */
    /* __ICACHE_PRESENT and __DCACHE_PRESENT are defined in demosoc.h */
    SystemInit();
    EnableICache();

    /* Initialize exception default handlers */
    Exception_Init();
    /* Initialize NMI handlers */
    Exception_Register_EXC(NMI_EXCn, (unsigned long)nmi_handler);
    /* ECLIC initialization, mainly MTH and NLBIT */
    eclic_level_threshold_set(0);
    eclic_priority_group_set(ECLIC_PRIGROUP_LEVEL2_PRIO2);
    eclic_global_interrupt_enable();

    /* Before enter into main, disable mcycle and minstret counter by default to save power */
    __disable_all_counter();
}

/**
 * \brief _fini function called in __libc_fini_array()
 * \details
 * This `__libc_fini_array()` function is called when exit main.
 * user need to implement this function, otherwise when link it will
 * error fini.c:(.text.__libc_fini_array+0x28): undefined reference to `_fini'
 * \note
 * Please use \ref _postmain_fini function now
 */
void _fini(void)
{
    /* Don't put any code here, please use _postmain_fini now */
}
