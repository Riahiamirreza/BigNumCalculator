#include <stdlib.h>
#include "numobj.h"


void add_numobj(const NumObj* a, const NumObj* b, NumObj* res) {
    Chunk* pdata = (Chunk)malloc(calculate_size_of_add(a, b));
    res->size = 0;
    Chunk carry = 0;
    for (int i = 0; i < SMALLER_SIZE(a, b); i++) {
        pdata[i] = a->data[i] + b->data[i] + carry;
        carry = get_carry(a->data[i], b->data[i]);
        res->size++;
    }
    res->data = pdata;
}

size_t calculate_size_of_add(const NumObj* a, const NumObj* b) {
    return a->size > b->size ? a->size + 1: b->size + 1;
}

Chunk get_carry(const Chunk x, const Chunk y) {
    return x + y < x || x + y < y ? 1:0;
}