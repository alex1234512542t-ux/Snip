#include <stdlib.h>
#include "./include/Vector.h"

Vector *Vector_init(size_t itemSize){
    Vector *vec = calloc(1, sizeof(Vector));
    vec->itemSize = itemSize;
    vec->size = 0;
    vec->items = 0;
    return vec;
}

void Vector_push(Vector *vec, void *item){
    if(!item){
        printf("\n!ERROR! ITEM IS NULL AT VECTOR PUSH\n");
        return;
    }
    if(!vec->items){
        vec->size+=1;
        vec->items = calloc(1, vec->itemSize);
        vec->items[vec->size-1] = item;
        return;
    }
    vec->size+=1;
    vec->items = realloc(vec->items, vec->size * vec->itemSize);
    vec->items[vec->size-1] = item;
}

void *Vector_get(Vector *vec, size_t index){
    if(index >= vec->size){
        printf("\nERROR ARRAY OUT OF BOUNDS EXCEPTION\n");
        return NULL;
    }
    return vec->items[index]; 
}



