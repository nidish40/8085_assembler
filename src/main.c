#include <stdio.h>
#include <string.h>
#include "lexer.h"
#include "parser.h"
#include "assembler.h"

int main(int argc, char *argv[]) {

    printf("8085 Assembler running...\n");

    if (argc < 2) {
        printf("Usage: assembler <file.asm>\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error: Cannot open file %s\n", argv[1]);
        return 1;
    }

    char line[200];
    char tokens[MAX_TOKENS][20];
    ParsedLine p;
    unsigned char bytes[4];

    while (fgets(line, sizeof(line), fp)) {

        int count = tokenize_line(line, tokens);
        if (count == 0)
            continue; // empty or comment-only

        parse_tokens(tokens, count, &p);

        int len = assemble_instruction(&p, bytes);

        printf("%-20s  ->  ", line); // print original line

        for (int i = 0; i < len; i++)
            printf("%02X ", bytes[i]);

        printf("\n");
    }

    fclose(fp);
    return 0;
}
