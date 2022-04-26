/*
 * e_3.1.
 * 
 * Status
 *	done
 *
 * Description
 *	Write binsearch version with only one test inside a loop
 */
#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
	const int n = 1e+6;
	int i, a[n];
	int fnd = 23456;
	
	for (i = 0; i < n; ++i)
		a[i] = i;

	if ((i = binsearch(fnd, a, n)) == -1)
		printf("element %d not found\n", fnd);
	else
		printf("element %d found at position: %d\n", fnd, i);
	
	return (0);
}

int binsearch(int x, int v[], int n)
{
	int low, mid, high;

	low = 0;
	high = n - 1;
	
	while (low < high) {
		mid = (high + low) / 2;
		if (x <= v[mid])
			high = mid;
		else
			low = mid + 1;
	}
	if (x == v[high])
		return high;
	return -1;
}

/* original */
/*
int binsearch(int x, int v[], int n)
{
	int low, mid, high;

	low = 0;
	high = n - 1;
	
	while (low <= high) {
		mid = (high + low) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
*/
