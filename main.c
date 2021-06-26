#include <stdio.h>
#include <stdlib.h>
#include "operations.c"



int main(int argc, char **argv){

	uint8_t a[3] = {3, 3, 6};
	uint8_t b[3] = {5, 3, 4};
	uint8_t c[3];
	//addition(3, a,b,c);
	subtraction(3, a,b,c);
	for(int i=0; i<3; i++)
		printf("%d-", c[i]);

	fputc('\n', stdout);
	return 0;
}
