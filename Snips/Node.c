#include "./include/Node.h"
#include "Macro.c"
#include <stdlib.h>

Node *Node_init(NodeType type){
    Node *node = calloc(1,sizeof(Node));
    node->type = type;
    
    switch(node->type){
        case NT_Macro:
            node->body = (void*)Macro_init(MT_Static);
            break;
        case NT_MacroParams:
            node->body = (void*)Macro_init(MT_Dynamic);
            break;
        case NT_Var:
            node->body = (void*)Variable_init("", "");
            break;

    }
    return node;

}
