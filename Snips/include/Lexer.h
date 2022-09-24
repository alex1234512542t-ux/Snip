#ifndef LEXER_H
#define LEXER_H
#include "./Vector.h"
#include "./Token.h"
typedef struct {
    size_t index; 
    char *content;
    char currChar;
    Vector *tokens;
}Lexer;

Lexer *Lexer_init(char *content);

static void Lexer_next(Lexer *lexer);

static void Lexer_back(Lexer *lexer);

static char *Lexer_LexSymbol(Lexer *lexer);

static char *Lexer_LexNumber(Lexer *lexer);

static char *lexer_lexString(Lexer *lexer);

static char *Lexer_lexBetweenSymbols(Lexer *lexer, char start, char end);

static Token *Lexer_lex(Lexer *lexer);

void Lexer_printTokens(Lexer *lexer);

void Lexer_start(Lexer *lexer);
#endif
