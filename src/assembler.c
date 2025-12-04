#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "assembler.h"
#include "opcode_table.h"

//converts register letter to register code 

int reg_code(char reg){
    switch(reg){
        case 'A': return 7;
        case 'B': return 0;
        case 'C': return 1;
        case 'D': return 2;
        case 'E': return 3;
        case 'H': return 4;
        case 'L': return 5; 
        case 'M': return 6; //memory
        default: return -1; //invalid
    }
}

// Assemble using a ParsedLine
int assemble_instruction(ParsedLine *p, unsigned char output[]) {

    const Opcode *op = find_opcode(p->mnemonic);
    if (!op) {
        printf("Error: Unknown instruction '%s'\n", p->mnemonic);
        return 0;
    }

    switch (op->optype) {

        case OP_NONE:     // HLT, NOP
            output[0] = op->opcode;
            return 1;

        case OP_REG:      // ADD B
            output[0] = op->opcode + reg_code(p->op1[0]);
            return 1;

        case OP_REG_IMM8: // MVI A, 32H
            output[0] = op->opcode + (reg_code(p->op1[0]) << 3);
            output[1] = (unsigned char)strtol(p->op2, NULL, 16);
            return 2;

        case OP_ADDR16:   // JMP 2050H
            output[0] = op->opcode;
            unsigned int addr = strtol(p->op1, NULL, 16);
            output[1] = addr & 0xFF; //lower byte
            output[2] = (addr >> 8) & 0xFF; //upper byte
            return 3;
    }

    return 0;
}