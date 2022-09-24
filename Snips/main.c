/* Output of one program is input of another program Using Pipes */

#include <unistd.h>

#include "FileHandler.c"
/* Pipe the output of program to the input of another. */
#include "./multiDirect.c"

#include "./Lexer.c"
#include "./Parser.c"
int main(int argc, char **argv){
    if(argc < 2){
        printf("\nNOT ENOUGH ARGS\n");
        exit(1);
    }
    char *content;
    char *fileName = argv[1];
    if(file_exists(fileName)){
        content = read_file(fileName);
    }else{
        printf("FILE %s DOESN'T EXIST", fileName);
        exit(1);
    }
     
    Lexer *lexer = Lexer_init(content);
    Lexer_start(lexer);
    Lexer_printTokens(lexer);
    Parser *parser = Parser_init(lexer->tokens);
    Parser_start(parser);
    //printf("%s", content);
    //printDirect();
    return 0;
}


