#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    size_t size; 
    size_t itemSize;
    void **items;
}Vector;

Vector *Vector_init(size_t itemSize);

void Vector_push(Vector *vec, void *item);

void *Vector_get(Vector *vec, size_t index);

#endif
