#ifndef LEXER_H
#define LEXER_H

#define MAX_TOKENS 10

int tokenize_line(const char *line, char tokens[MAX_TOKENS][20]);

#endif