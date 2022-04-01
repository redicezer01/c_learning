#include <stdio.h>

/* ftoc: converts Fahrenheit to Celcius
*/
float ftoc(float f);

/* вывод таблицы температур по Фаренгейту и Цельсию
     для fahr = 0, 20, ..., 300;
     версия с вещественной арфиметикой */	
main() {
	float fahr, celcius;
	int lower, upper, step;
	
	lower = 0;	/* нижняя граница темпиратур в таблице */
	upper = 300;	/* верхняя граница */
	step = 20;	/* величина шага */

	printf("  F      C\n");
	printf("----------\n");
	fahr = lower;
	while(fahr <= upper) {
		celcius = ftoc(fahr);
		printf("%3.0f %6.1f\n", fahr, celcius);
		fahr = fahr + step;
	}
}

float ftoc(float f) {
	return (5.0/9.0) * (f-32);
}

int test();
int test() {
	printf("test\n");
	return 0;
}
