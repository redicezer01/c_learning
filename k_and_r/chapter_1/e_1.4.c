/*
 * e_1.4.
 *
 * Status
 *	done
 *
 * Description
 * 	Celsius to Fahrenheit	
 */
#include <stdio.h>

/*
 * print Fahrenheit-Celcius table
 * for celcius = -30, -25, ..., 50;
 */
main() {
	float fahr, celcius;
	int lower, upper, step;
	
	lower = -30;	/* lower limit of temperature table */
	upper = 50;	/* upper limit */
	step = 5;	/* step size */

	/* heading */
	printf("  C      F\n");
	printf("----------\n");

	celcius = lower;
	while(celcius <= upper) {
		fahr = celcius * 9.0 / 5.0 + 32;
		printf("%3.0f %6.1f\n", celcius, fahr);
		celcius = celcius + step;
	}
}
