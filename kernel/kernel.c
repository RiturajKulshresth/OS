#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "kernel.h"
#include "../libc/string_alloc.h"
#include <stdint.h>

void kernel_main() {
    isr_install();
    irq_install();
    kprint("Type something, it will go through the kernel\nType ROC for animation\nType CLR to clear the screeen\nType END to halt the CPU\nType MEM to request a page address\nType any other text to reflect\nshell $ ");
}

void user_input(char *input) {
    if (strcmp(input, "END") == 0) {
        kprint("Stopping the CPU. Bye!\n");
        asm volatile("hlt");
    } else if (strcmp(input, "MEM") == 0) {
        uint32_t phys_addr;
        uint32_t page = kmalloc(1000, 1, &phys_addr);
        char page_str[16] = "";
        hex_to_ascii(page, page_str);
        char phys_str[16] = "";
        hex_to_ascii(phys_addr, phys_str);
        kprint("Page: ");
        kprint(page_str);
        kprint(", physical address: ");
        kprint(phys_str);
        kprint("\n");
    }
    else if (strcmp(input, "CLR")==0){
        clear_screen();
    }
    else if (strcmp(input, "ROC")==0){
        rocket();
        clear_screen();
        kprint("\nshell $ ");
    }
    kprint("You said: ");
    kprint(input);
    kprint("\nshell $ ");
}