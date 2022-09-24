#ifndef MACRO
#define MACRO

#include "Vector.h"

typedef enum{
    MT_Static = 0,
    MT_Dynamic = 1
}MacroType;

typedef struct {
    char *name;
    char *content;
    MacroType type;
    Vector *params;
}Macro;

Macro *Macro_init(MacroType type);

#endif
