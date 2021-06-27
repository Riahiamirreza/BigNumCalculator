#include <math.h>
#include "operations.c"

/* This function multiply the a integer by x and add y */
void mul_add(uint8_t *a, int *len, uint8_t x, uint8_t y){

	int i;
	uint8_t p1, p2;
	uint8_t carry = y;
	for(i=0; i<(*len); i++){
		mul_32_by_32(a[i], x, &p1, &p2);
		p2   += carry;
		carry = p1 + (p2 < carry);
		a[i]  = p2;
	}
	if (carry){
		a[*len] = carry;
		(*len)++;
	}

}

void str2int(int s_len, char *s, int *u_len, uint8_t *u){

	uint8_t chunk = 0;
	int i;
	*u_len = 0;
	static const uint8_t pow10[] = {100, 10};
	for(i=1; i<=s_len; i++){
		chunk = chunk*10 + *s - '0';
		*s++;
		if(i%2 == 0 || i==s_len){
			mul_add(u, u_len, pow10[i%2], chunk);
			chunk = 0;
		}
	}
	
}

