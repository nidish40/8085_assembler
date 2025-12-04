#include <string.h>
#include "parser.h"

void parse_tokens(char tokens[][20], int count, ParsedLine *out){
    
    //clear mnemonics
    out->mnemonic[0] = '\0';
    out->op1[0] = '\0';
    out->op2[0] = '\0';

    out->operand_count = 0;

    if(count ==0)
        return;
    
    //first token is always mnemonic
    strcpy(out->mnemonic, tokens[0]);

    if(count>1){
        strcpy(out->op1, tokens[1]);
        out->operand_count = 1;
    }

    if(count>2){
        strcpy(out->op2, tokens[2]);
        out->operand_count = 2;
    }
}