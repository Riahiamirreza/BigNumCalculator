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

/*
 * return 1  if a>b
 * return 0  if a=b
 * return -1 if a<b
 */
int compare(int a_len, uint8_t *a, int b_len, uint8_t *b){

	if(a_len != b_len)
		return (a_len > b_len) ? a_len : b_len;
	int i;
	for(i=a_len-1; i>=0; i--){
		if(a[i]>b[i])
			return 1;
		else if(a[i]<b[i])
			return -1;
	}
	return 0;
}


void subtraction(int len, uint8_t *a, uint8_t *b, uint8_t *c){
	
	bool carry = 0;
	int i;
	for(i=0; i<len; i++){

		c[i]  = (a[i]-carry) - b[i];
		carry = (a[i]-carry<b[i]);
		
	}

}

void mul_32_by_32(uint8_t a, uint8_t b, uint8_t *p1, uint8_t *p2){

	uint16_t mul;
	mul = (uint16_t)a*b;
	*p1 = (uint8_t)(mul >> 8);// 8 more signifant bits stores in p1.
	*p2 = (uint8_t)mul;	  // other other bits stores in p2.

}
