#ifndef STRINGS_ALLOC_H
#define STRINGS_ALLOC_H

#include <stdint.h>
#include <stddef.h>

void int_to_ascii(int n, char str[]);
void hex_to_ascii(int n, char str[]);
void reverse(char s[]);
int strlen(char s[]);
void backspace(char s[]);
void append(char s[], char n);
int strcmp(char s1[], char s2[]);
void rocket();
void delay();
// alloc mem
void memory_copy(uint8_t *source, uint8_t *dest, int nbytes);
void memory_set(uint8_t *dest, uint8_t val, uint32_t len);
uint32_t kmalloc(size_t size, int align, uint32_t *phys_addr);


#define UNUSED(x) (void)(x)
#endif
