#ifndef PARSER_H
#define PARSER_H
#include "./Vector.h"
#include "./Token.h"

typedef struct {
    size_t index;
    Vector *tokens;
    Vector *nodes;   
    Token *currToken;
}Parser;

Parser *Parser_init(Vector *tokens);

static void Parser_next(Parser *parser);

#endif
