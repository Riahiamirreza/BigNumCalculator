#include <stdio.h>
#include "numobj.h"

int main(int argc, char **argv){
    NumObj* a = new_numobj(10);
    NumObj* b = new_numobj(10);
    NumObj* c = new_numobj(10);
    PRINT_NUMOBJ(c);
    add_numobj(a, b, c);
    PRINT_NUMOBJ(c);

}
