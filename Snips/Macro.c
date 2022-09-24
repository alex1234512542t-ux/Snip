#include "./include/Macro.h"
#include "./Variable.c"
#include <stdlib.h>

Macro *Macro_init( MacroType macType ){
    Macro *mac = calloc(1, sizeof(Macro));
    mac->name = "";
    mac->content = "";
    mac->type =macType;
    mac->params = Vector_init(sizeof(Variable));
    return mac;
}
