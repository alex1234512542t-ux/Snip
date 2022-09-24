#include "./include/Lexer.h"
#include <stdlib.h>
#include "./Token.c"
#include <ctype.h>
#include "./Vector.c"
Lexer *Lexer_init(char *content){
    Lexer *lexer = calloc(1, sizeof(Lexer));
    lexer->index = 0;
    lexer->content = content;
    lexer->currChar = lexer->content[lexer->index];
    lexer->tokens = Vector_init(sizeof(Token));
    return lexer;
}

static void Lexer_skipWhiteSpace(Lexer *lexer){
    while(lexer->currChar == ' '&&lexer->currChar == '\n'&&lexer->currChar == '\n' && lexer->currChar == '\t' &&lexer->currChar != '\0'){
        Lexer_next(lexer);
    }
}

static void Lexer_next(Lexer *lexer){
    lexer->index += 1;
    lexer->currChar = lexer->content[lexer->index];
}

static void Lexer_back(Lexer *lexer){
    lexer->index -= 1;
    lexer->currChar = lexer->content[lexer->index];
}
static char *Lexer_lexSymbol(Lexer *lexer){
   char *value = malloc(sizeof(char));
    size_t size = 0;

    while ((isalpha(lexer->currChar) || isdigit(lexer->currChar) || lexer->currChar == '_') && lexer->currChar != '\0'){
        value[size] = lexer->currChar;
        size += 1;
        value = realloc(value, sizeof(char) * (size+1));
        char c = lexer->content[lexer->index + 1];
        
        if(isdigit(c) || isalpha(c) || c == '_'){
            Lexer_next(lexer);
            continue;
        }

        value[size] = '\0';
        break;
    }
    return value;
}
static char *Lexer_lexNum(Lexer *lexer){
    char *value = malloc(sizeof(char));
    size_t size = 0;
    int isFloat = 0;

    while ((isdigit(lexer->currChar) || lexer->currChar == '.'&&
            lexer->currChar != '\0')){
        //printf("%c", lexer->curr_char);
        if(lexer->currChar == '.' && isFloat == 0){
            isFloat = 1;
        }
        value[size] = lexer->currChar;
        size += 1;
        value = realloc(value, sizeof(char) * size + 1);
        value[size] = '\0';


        Lexer_next(lexer);
    }
    Lexer_back(lexer);
    //printf("test : %s", value);
    return value; 

}
static char *Lexer_lexStr(Lexer *lexer){
   // printf("\nstring is the prob\n");
    char *value = calloc(1, sizeof(char));
    size_t size = 0;
    Lexer_next(lexer);
    while(lexer->currChar != '"'){
        if(lexer->currChar == '\0'){
            printf("ERROR MISSING QUTATION MARK\n");
            exit(1);
        }
        
        value = realloc(value, (size+1) * sizeof(char));
        value[size] = lexer->currChar;
        size +=1;
        //free(temp);
        Lexer_next(lexer); 
    }
    return value;
}

static char *Lexer_lexBetweenSymbols(Lexer *lexer, char start, char end){
   // printf("\nstring is the prob\n");
    char *value = calloc(1, sizeof(char));
    size_t size = 0;
    size_t queue = 1;
    Lexer_next(lexer);
    while(lexer->currChar != end && queue != 0){
        if(lexer->currChar == '\0'){
            printf("ERROR MISSING %c MARK\n", end);
            exit(1);
        }
        if(lexer->currChar == start)
            queue+=1;
        if(lexer->currChar == end)
            queue-=1;
        value = realloc(value, (size+1) * sizeof(char));
        value[size] = lexer->currChar;
        size +=1;
        //free(temp);
        Lexer_next(lexer); 
    }
    value[size] = '\0';
    return value; 
}

static Token *Lexer_lex(Lexer *lexer){

    switch(lexer->currChar){
        case '#':
            return Token_init("#", TT_MacroDef);
        case '$':
            return Token_init("$", TT_VarDef);
        case '(':
            return Token_init("(", TT_LParen);
        case ')':
            return Token_init(")", TT_RParen);
        case '[':
            return Token_init("[", TT_LBracket);
        case ']':
            return Token_init("]", TT_RBracket);
        case ',':
            return Token_init(",", TT_Comma);
        case '&':
            return Token_init("&", TT_And);
        case '=':
            return Token_init("=", TT_Equal);
        case ';':
            return Token_init(";", TT_Semicolon);
        case '"':
            return Token_init(Lexer_lexStr(lexer), TT_String);
        case '{':
            return Token_init(Lexer_lexBetweenSymbols(lexer, '{', '}'), TT_Block);
    }
    if(isalpha(lexer->currChar)){
        return Token_init(Lexer_lexSymbol(lexer), TT_Symbol);
    }
    if(isdigit(lexer->currChar) || lexer->currChar == '.'){
        return Token_init(Lexer_lexNum(lexer), TT_Number);
    }
    
    
    char str[] = {lexer->currChar};
    return Token_init(str, TT_NAT);
}

void Lexer_printTokens(Lexer *lexer){
    for(int i = 0; i < lexer->tokens->size; i++){
        printf("\n-----Token %d-----\n", i); 
        printf("\nValue : %s", ((Token*)Vector_get(lexer->tokens, i))->value);
        printf("\nType : %s\n", TT_MAP[((Token*)Vector_get(lexer->tokens, i))->type]);
        
    }
}

void Lexer_start(Lexer *lexer){
    while(lexer->currChar != '\0'){
        Lexer_skipWhiteSpace(lexer);
        Token *tok = Lexer_lex(lexer);
        if(tok->type != TT_NAT) 
            Vector_push(lexer->tokens,(void*)tok);
        Lexer_next(lexer); 
    }
    Vector_push(lexer->tokens,(void*)Token_init("", TT_EOV));
}
