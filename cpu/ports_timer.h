#ifndef PORTS_TIMER_H
#define PORTS_TIMER_H

#include <stdint.h>

unsigned char port_byte_in (uint16_t port);
void port_byte_out (uint16_t port, uint8_t data);
unsigned short port_word_in (uint16_t port);
void port_word_out (uint16_t port, uint16_t data);


void init_timer(uint32_t freq);

#endif