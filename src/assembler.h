#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include "parser.h"

//assembles one line into machine bytes
int assemble_instruction(ParsedLine *p, unsigned char output[]);

#endif
