/* 
 * e_1.15.
 *
 * Status
 *	done
 *
 * Description
 *	temperature conversion program of Sectio 1.2
 *	using function for conversion
 */
#include <stdio.h>

/* ftoc: converts Fahrenheit to Celcius */
float ftoc(float f);

main() {
	float fahr, celcius;
	int lower, upper, step;
	
	lower = 0;	/* lower limit of temperature table */
	upper = 300;	/* upper limmt */
	step = 20;	/* step size */

	printf("  F      C\n");
	printf("----------\n");
	fahr = lower;
	while(fahr <= upper) {
		celcius = ftoc(fahr); /* function for conversion */
		printf("%3.0f %6.1f\n", fahr, celcius);
		fahr = fahr + step;
	}
}

float ftoc(float f) {
	return (5.0/9.0) * (f-32);
}
