/*
 * e_2.7.
 * 
 * Status
 *	done
 *
 * Description
 *	Write a function invert(x, p, n) that returns x with the n bits that
 *	begins at position p inverted, leaving others unchanged.
 *	
 */
#include <stdio.h>

/* invert(x, p, n) */
unsigned int invert(unsigned int x, unsigned int p, unsigned int n);

int main()
{
	int x = 621;

	printf("%10b\n", x);	
	printf("%10b\n", invert(x, 6, 2));	

	return (0);
}

/* invert(x, p, n) */
unsigned int invert(unsigned int x, unsigned int p, unsigned int n)
{

	unsigned int tpl;

	++p;
	/*
	 * --------------------------------------------------
	 * Algorithm
	 * --------------------------------------------------
	 *
	 * step 1: get the template: n bits set in position p
	 *	tpl = ~0U;
	 *	tpl = tpl << n;
	 *	tpl = ~tpl;
	 *	tpl <<= p-n;
	 *
	 * step 2: get n bits from x at position p	
	 *	r = x & tpl;
	 *
	 * step 3: invert only n bits at position p
	 *	r = ~r & tpl;
	 *
	 * step 4: insert inverted n bits to position p in x
	 *	r |= (x & ~tpl);
	*/
	
	/* step 1 */
	tpl = ((~(~0U << n)) << (p-n));
	
	/* step 2 ... step 4 */	
	return (~(tpl & x) & tpl) | (x & ~tpl);
}
