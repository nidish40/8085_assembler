#ifndef OPCODE_TABLE_H
#define OPCODE_TABLE_H

#include <stdint.h>

typedef enum {
    OP_NONE, //HLT and NOP
    OP_REG_IMM8, //Immediate to Register
    OP_REG, //Register to register 
    OP_ADDR16, //Address 16 bit
} OperandType;

typedef struct {
    const char *mnemonic; //"MVI"
    uint8_t opcode; //base opcode
    uint8_t size; //in bytes
    OperandType optype; // type of operands
} Opcode;

const Opcode* find_opcode(const char *mnemonic);

#endif