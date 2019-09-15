#ifndef EMULATOR_FUNCTIONS_H_
#define EMULATOR_FUNCTIONS_H_

#include <stdint.h>

#include "emulator.h"

/* Eflags */
#define CARRY_FLAG (1)
#define ZERO_FLAG (1 << 6)
#define SIGN_FLAG (1 << 7)
#define INT_ENABLE_FLAG (1 << 9)
#define DIRECTION_FLAG (1 << 10)
#define OVERFLOW_FLAG (1 << 11)

/* Source Instruction Operations */

uint32_t get_code8(Emulator *emu, int index);

int32_t get_sign_code8(Emulator *emu, int index);

uint32_t get_code32(Emulator *emu, int index);

int32_t get_sign_code32(Emulator *emu, int index);

/* Memory Operations */

void set_memory8(Emulator *emu, uint32_t address, uint32_t value);

void set_memory32(Emulator *emu, uint32_t address, uint32_t value);

uint32_t get_memory8(Emulator *emu, uint32_t address);

uint32_t get_memory32(Emulator *emu, uint32_t address);

/* Register Operations */

void set_register8(Emulator *emu, int index, uint8_t value);

uint8_t get_register8(Emulator *emu, int index);

void set_register32(Emulator *emu, int reg_index, uint32_t value);

uint32_t get_register32(Emulator *emu, int reg_index);

/* Stack Operations */

void push32(Emulator *emu, uint32_t value);

uint32_t pop32(Emulator *emu);

/* Eflag Operations */

void set_carry_flag(Emulator *emu, int is_carry);
void set_zero_flag(Emulator *emu, int is_zero);
void set_sign_flag(Emulator *emu, int is_sign);
void set_int_flag(Emulator *emu, int is_enabled);
void set_direction_flag(Emulator *emu, int is_down);
void set_overflow_flag(Emulator *emu, int is_overflow);

int32_t is_carry(Emulator *emu);
int32_t is_zero(Emulator *emu);
int32_t is_sign(Emulator *emu);
int32_t is_int_enabled(Emulator *emu);
int32_t is_direction_down(Emulator *emu);
int32_t is_overflow(Emulator *emu);

void update_eflags_add(Emulator *emu, uint32_t value1, uint32_t value2, uint64_t result);
void update_eflags_sub(Emulator *emu, uint32_t value1, uint32_t value2, uint64_t result);

#endif
