#ifndef PARSER_H
#define PARSER_H

//hold one instruction data
typedef struct {
    char mnemonic[20];
    char op1[20];
    char op2[20];
    int operand_count;
} ParsedLine;

void parse_tokens(char tokens[][20], int count, ParsedLine *out);

#endif