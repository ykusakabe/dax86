#ifndef EMULATOR_H_
#define EMULATOR_H_

#include <stdint.h>

/*
 * In order of REG of ModR/M
 * EAX: 000, ECX: 001 ... EDI: 111
 * 
 * 32  | 16 | 8  | 8
 * EAX | AX | AH | AL
 * EBX | BX | BH | BL
 * ECX | CX | CH | CL
 * EDX | DX | DH | DL
 * ESI
 * EDI
 * ESP
 * EBP
 */
enum Register
{
    EAX,
    ECX,
    EDX,
    EBX,
    ESP,
    EBP,
    ESI,
    EDI,
    REGISTERS_COUNT,
    AL = EAX,
    CL = ECX,
    DL = EDX,
    BL = EBX,
    AH = AL + 4,
    CH = CL + 4,
    DH = DL + 4,
    BH = BL + 4
};

enum SegmentRegister
{
    CS,
    DS,
    ES,
    SS,
    FS,
    GS,
    SEGMENT_REGISTERS_COUNT
};

enum ControlRegister
{
    CR0,
    CR1,
    CR2,
    CR3,
    CR4,
    CONTROL_REGISTER_COUNT
};

typedef struct
{
    uint32_t eflags;
    uint32_t registers[REGISTERS_COUNT];
    uint16_t segment_registers[SEGMENT_REGISTERS_COUNT];
    uint32_t control_registers[CONTROL_REGISTER_COUNT];
    uint8_t *memory;
    uint32_t eip;
} Emulator;

#endif