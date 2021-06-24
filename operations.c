#include <stdint.h>
#include <stdbool.h>

void addition(int len, uint8_t *a, uint8_t *b, uint8_t *c){

	bool carry = 0;
	int i;
	for(i=0; i<len; i++){
		
		c[i] = carry;
		uint8_t s = a[i] + b[i];

		if(s<a[i] || s<b[i]){
			puts("here");
			carry = 1;
		}else{
			carry = 0;
		}
		c[i] += a[i] + b[i];
			
	}
	c[i] = carry;
}


