#ifndef NUM_OBJ_H
#define NUM_OBJ_H

#include <stdbool.h>

#define SMALLER_SIZE(x, y) x->size > y->size ? x->size:y->size

typedef unsigned char Chunk;

typedef struct 
{

    Chunk* data;
    bool is_positive;
    size_t size;

} NumObj;

/*
 * Add a and b and store the result in res.
 */
void add_numobj(const NumObj* a, const NumObj* b, NumObj* res);

#endif