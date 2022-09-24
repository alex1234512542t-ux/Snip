#ifndef NODE_H 
#define NODE_H

typedef enum{
    NT_Macro = 0,
    NT_MacroParams = 1,
    NT_Var = 2
}NodeType;

typedef struct{
    NodeType type;
    void *body;
}Node;

Node *Node_init(NodeType type);

#endif
