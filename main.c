#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.c"


int main(int argc, char **argv){

	uint8_t c[10];
	int *t;
	int g = 0;
	t = &g;
	str2int(strlen(argv[1]), argv[1], t, c);
	for(int i=0; i<*t; i++)
		printf("%d-", c[i]);
	fputc('\n', stdout);
	return 0;
}
