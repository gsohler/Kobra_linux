/*
 * HC32F46x.ld generic setup.
 */
MEMORY
{
    IROM1  (rx) : org = 0x00008000, len = 448k
    IRAM1  (wx) : org = 0x20000000, len = 64k 
    IRAM2  (wx) : org = 0x20010000, len = 64k 
 }


/*  ENTRY(Reset_Handler) */

SECTIONS
{

    .text : ALIGN(4)
    {
        __init_array_base__ = .;
        KEEP(*(.vectors))
        KEEP(*(.init_array))
        __init_array_end__ = .;
        __fini_array_base__ = .;
        KEEP(*(.fini_array))
        KEEP(*(SORT(.fini_array.*)))
        *(.text)
        *(.text.*)
        *(.rodata)
        *(.rodata.*)
        *(.glue_7t)
        *(.glue_7)
        *(.gcc*)
        __exidx_start = .;
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        __exidx_end__ = .;
        __exidx_end = .;
	end = . ;
    } > IROM1

    .data : ALIGN(4)
    {
        __data_base__ = .;
        *(.data)
        *(.data.*)
        . = ALIGN(4);
        __data_end__ = .;
    } > IRAM1

    .ARM.exidx : {
     } > IROM1


}
/*
LR_IROM1 0x00008000 0x00078000  {    ; load region size_region
  ER_IROM1 0x00008000 0x00078000  {  ; load address = execution address
   *.o (RESET, +First)
   *(InRoot$$Sections)
   .ANY (+RO)
   .ANY (+XO)
  }
  RW_IRAM1 0x20000000 0x00010000  {  ; RW data
   .ANY (+RW +ZI)
  }
  RW_IRAM2 0x20010000 0x00010000  {
   .ANY (+RW +ZI)
  }
}
*/
