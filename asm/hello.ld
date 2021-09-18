ENTRY(start)

SECTIONS
{
	. = 0x10000;
	.text : { *(.text) }
}
