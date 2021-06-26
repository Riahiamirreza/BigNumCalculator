#include <stdint.h>
#include <stdbool.h>



void addition(int len, uint8_t *a, uint8_t *b, uint8_t *c){

	bool carry = 0;
	int i;
	for(i=0; i<len; i++){
		
		c[i] = carry;
		uint8_t s = a[i] + b[i];

		if(s<a[i] || s<b[i])
			carry = 1;
		else
			carry = 0;
		
		c[i] += a[i] + b[i];
			
	}
	c[i] = carry;
}


void subtraction(int len, uint8_t *a, uint8_t *b, uint8_t *c){
	
	bool carry = 0;
	int i;
	for(i=0; i<len; i++){

		c[i]  = (a[i]-carry) - b[i];
		carry = (a[i]-carry<b[i]);
		
	}

}
