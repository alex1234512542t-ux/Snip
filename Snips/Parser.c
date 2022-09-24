#include "./include/Parser.h"

#include "./Node.c"
#include <stdlib.h>
#include <string.h>
Parser *Parser_init(Vector *tokens){
    Parser *parser = calloc(1,sizeof(Parser));
    parser->index = 0;
    parser->tokens = tokens;
    parser->nodes = Vector_init(sizeof(Node_init));
    parser->currToken = Vector_get(parser->tokens, parser->index);
    return parser;
}

static void Parser_next(Parser *parser){
    parser->index += 1;
    parser->currToken =((Token*) Vector_get(parser->tokens, parser->index));
}



Node *Parser_parse(Parser *parser){
    switch(parser->currToken){
        //Finds the symbol denototing a macro
        case TT_MacroDef: //#
            //checks to see if macro is a redefinition
            
            Parser_next(parser); 

            if(strcmp(parser->currToken->value)){
            }
            break;
    }    
}

void Parser_start(Parser *parser){
    printf("\n-----parer---------\n");
    while(parser->currToken->type != TT_EOV){
        Parser_next(parser);
        printf("%s", parser->currToken->value);
    }
}
