#ifndef INT_H_
#define INT_H_

#include "emulator.h"

#define T_IRQ0 32 // IRQ 0 corresponds to int T_IRQ

#define IRQ_TIMER 0
#define IRQ_KBD 1
#define IRQ_COM1 4
#define IRQ_IDE 14
#define IRQ_ERROR 19
#define IRQ_SPURIOUS 31

uint8_t write_interrupt(Emulator *emu, uint8_t irq);

#endif