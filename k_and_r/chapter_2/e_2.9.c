/*
 * 2.9.
 * faster versio of bitcount function
 */

#include <stdio.h>

int bitcount(unsigned x);
int bitcounto(unsigned x);

int main()
{
	int c;

	printf("x &= x - 1\n");
	c = bitcount(581);
	printf("number of 1-bits: %2d\n\n", c);

	printf("x >>= 1\n");
	c = bitcounto(581);
	printf("number of 1-bits: %2d\n", c);

	return 0;
}

/* 
 * faster version 
 * x &= x - 1 deletes the rightmost 1-bit in x
 * bitcount: counts 1 bits in x
 */
int bitcount(unsigned x)
{
	int b, i;

	i = 0;	
	for (b = 0; x != 0; x &= x-1) {
		b++;
		i++;
	}
	printf("loop iterations: %3d\n", i);
	return b;
}

/* 
 * orig
 * bitcount: counts 1 bits in x
 */
int bitcounto(unsigned x)
{
	int b, i;

	i = 0;	
	for (b = 0; x != 0; x >>= 1) {
		if (x & 01)
			b++;
		i++;
	}
	printf("loop iterations: %3d\n", i);
	return b;
}
