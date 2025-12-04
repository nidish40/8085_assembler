#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"

//converts a line of assembly code into tokens
int tokenize_line(const char *line, char tokens[MAX_TOKENS][20]){
    int t = 0; //token count
    int i = 0; //index into tokens[t]

    for(int pos=0;line[pos]!='\0';pos++){
        char c = line[pos];

        if(c==';'){ //skip comments starting with ;
            break;
        }

        //delimiters
        if(c==' '||c=='\t'|| c ==','||c==':'||c=='\n'){

            if(i>0){
                tokens[t][i] = '\0'; //end the token
                t++;
                i=0;
            }
        }else{
            if(i<19){
                tokens[t][i++] = c;
            }
        }
    }
    if(i>0){
        tokens[t][i] = '\0';
        t++;
    }

    return t; //return size of the line
}
