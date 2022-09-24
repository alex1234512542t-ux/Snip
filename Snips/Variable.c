#include "./include/Variable.h"
#include <stdlib.h>

Variable *Variable_init(char *orgin, char *value){
    Variable *var = calloc(1, sizeof(Variable));
    var->orgin = orgin;
    var->value = value;
    return var;
}

