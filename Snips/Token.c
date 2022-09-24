#include "./include/Token.h"
#include <stdlib.h>

Token *Token_init(char *val, TokenType type){
    Token *tok = calloc(1, sizeof(Token));

    tok->value = val;
    tok->type =type;
    return tok;
}

