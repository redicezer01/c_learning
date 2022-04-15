/*
 * e_2.8.
 * 
 * Status
 *	done
 *
 * Description
 *	Write a function rightrot(x, n) that returns 
 *	value of the integer x rotated to the right
 *	by n bit positions.
 */
#include <stdio.h>

unsigned int rightrot(unsigned int x, unsigned int n);
unsigned int sizebuint();

int main()
{
	printf("%32b\n", 175U);	
	printf("%32b\n", rightrot(175U, 4U));	
	return (0);
}

unsigned int rightrot(unsigned int x, unsigned int n)
{
	unsigned int bits;
	/* bits = sizebuint(); */
	bits = sizeof(unsigned int) * 8;
	return (x & ~((~0U) << n)) << (bits-n) | (x >> n);
}

/* without sizeof counts bits in unsigned int */
unsigned int sizebuint()
{
	unsigned int i;
	unsigned uint_v = ~0U;
	for (i = 0; uint_v != 0; ++i)
		uint_v <<= 1;

	return i;
}
