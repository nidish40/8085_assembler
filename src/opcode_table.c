#include <string.h>
#include "opcode_table.h"

static const Opcode table[] = {
    {"NOP", 0x00, 1, OP_NONE},
    {"HLT", 0x76, 1, OP_NONE},
    {"ADD", 0x80, 1, OP_REG},
    {"MVI", 0x06, 2, OP_REG_IMM8},
    {"JMP", 0xC3, 3, OP_ADDR16}
};

static const size_t table_size = sizeof(table) / sizeof(table[0]);

const Opcode* find_opcode(const char *mnemonic) {
    for (size_t i = 0; i < table_size; i++) {
        if (strcmp(table[i].mnemonic, mnemonic) == 0) {
            return &table[i];
        }
    }
    return NULL; // Not found
}