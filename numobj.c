#include <stdlib.h>
#include "numobj.h"


size_t calculate_size_of_add(const NumObj* a, const NumObj* b) {
    return a->size > b->size ? a->size + 1: b->size + 1;
}

Chunk get_carry(const Chunk x, const Chunk y) {
    return (Chunk)(x + y) < x || (Chunk)(x + y) < y ? 1:0;
}

void add_numobj(const NumObj* a, const NumObj* b, NumObj* res) {
    Chunk* pdata = (Chunk*)malloc(calculate_size_of_add(a, b));
    res->size = 0;
    Chunk carry = 0;
    for (int i = 0; i < SMALLER_SIZE(a, b); i++) {
        pdata[i] = a->data[i] + b->data[i] + carry;
        carry = get_carry(a->data[i], b->data[i]);
        res->size++;
    }
    res->data = pdata;
}

NumObj* new_numobj(const size_t size) {
    NumObj* obj = (NumObj*)malloc(sizeof(NumObj));
    Chunk* pdata = (Chunk*)malloc(size);
    obj->data = pdata;
    obj->sign = 0;
    obj->size = size;
    return obj;
}

size_t calculate_long_size(long i) {
    size_t s = 0;
    while (i) {
        i /= 256;
        s++;
    }
    return s;
}


NumObj* numobj_fromlong(long x) {
    NumObj* obj = (NumObj*)malloc(sizeof(NumObj));
    obj->size = calculate_long_size(x);
    Chunk* pdata = (Chunk*)malloc(obj->size);

    for (int i = 0; i < obj->size; i++) {
        pdata[i] = x%256;
        x /= 256;
    }
    obj->data = pdata;
    return obj;
}
