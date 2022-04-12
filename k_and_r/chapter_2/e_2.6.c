/*
 * e_2.6.
 * 
 * Status
 *	done
 *
 * Description
 *	setbits(x, p, n, y) returns x with the n bits that begin
 *	at the position p set to the rightmost n bitd of y,
 *	leaving other bits unchanged
 *	
 */
#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main()
{
	/*
	int x = 118;
	int p = 2;
	int n = 3;
	int y = 26;
	*/
	/* 106 */

	int x = 57;
	int p = 1;
	int n = 4;
	int y = 105;
	/* 51 */

	printf("p: %d, n: %d\n", p, n);
	printf("x:       %8b\n", x);
	printf("y:       %8b\n", y);
	printf("setbits: %8b\n", setbits(x,p,n,y));
	return 0;
}

int setbits(int x, int p, int n, int y)
{
	/* step 01: ~0  - all 1-bits (111111...)
	 * step 02: <<n - last n bits set to 0
	 * step 03: ~   - invert (all 0 and last n bits 1)
	 * step 04: <<p - shift n 1-bits to the position
	 * step 05: ~   - all 1 and n bits from position p is 0
	 * step 06: &x  - set n bits from p position to 0
	 * 
	 * step 07: ~0  - all 1-bits (1111111...)
	 * step 08: <<n - last n bits set to 0
	 * step 09: ~   - last n bits set to 1
	 * step 10: &y  - turn all bits to 0 except last n
	 * step 11: <<p - shift last n bits to position p
	 * step 12: |   - making n bits in x from position p equals to
	 *		  last n bits of y
	 */
	return (~((~((~0)<<n))<<p)&x) | ((~(~0<<n)&y)<<p);
}
