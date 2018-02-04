ENTRY(entry)
SECTIONS
{
  . = 0x10000000;
  .text : { *(.entry) }
  .text : { *(.text) }

  . = 0x20000000;
  .data : { *(.data) }
  .bss : { *(.bss) }
}
