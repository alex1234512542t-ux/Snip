#ifndef TOKEN_H
#define TOKEN_H

typedef enum{
    TT_Symbol = 0,
    TT_MacroDef = 1,
    TT_VarDef = 2,
    TT_LParen = 3,
    TT_RParen = 4,
    TT_LBracket = 5,
    TT_RBracket = 6,
    TT_LCurlyBrace = 7,
    TT_RCurlyBrace = 8,
    TT_And = 9,
    TT_Equal = 10,
    TT_Semicolon = 11,
    TT_Number = 12,
    TT_String = 13,
    TT_Block = 14,
    TT_Comma = 15,
    TT_NAT = 16,
    TT_EOV = 17
}TokenType;

char *TT_MAP[] = {
    "TT_Symbol",
    "TT_MacroDef",
    "TT_VarDef",
    "TT_LParen",
    "TT_RParen",
    "TT_LBracket",
    "TT_RBracket",
    "TT_LCurlyBrace",
    "TT_RCurlyBrace",
    "TT_And",
    "TT_Equal",
    "TT_Semicolon",
    "TT_Number",
    "TT_String",
    "TT_Block",
    "TT_Comma",
    "TT_NAT",
    "TT_EOV"
};
    

typedef struct {
    char *value;
    TokenType type;    
}Token;

Token *Token_init(char *val, TokenType type);
#endif
