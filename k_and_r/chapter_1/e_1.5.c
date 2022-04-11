/*
 * e_1.5.
 *
 * Status
 *	done
 *
 * Description
 *	print Fahrenheit-Celsius temperature conversion table in reverse order
 */
#include <stdio.h>

main() {
	int fahr;
	for(fahr = 300; fahr >= 0; fahr = fahr - 20)
		printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr-32));
}
