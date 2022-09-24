#ifndef VARIABLE_H
#define VARIABLE_H

typedef struct{
    char *orgin;
    char *value;
}Variable;

Variable *Variable_init(char *orgin, char *value);

#endif
