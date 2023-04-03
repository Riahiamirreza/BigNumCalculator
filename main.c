#include <stdio.h>
#include <stdlib.h>

#include "numobj.h"

int main(int argc, char **argv){

    if (argc > 2) {
        NumObj* a = numobj_fromlong(atol(argv[1]));
        NumObj* b = numobj_fromlong(atol(argv[2]));
        NumObj* c = new_numobj(0);
        PRINT_NUMOBJ(a);
        PRINT_NUMOBJ(b);
        add_numobj(a, b, c);
        PRINT_NUMOBJ(c);
    }
}
