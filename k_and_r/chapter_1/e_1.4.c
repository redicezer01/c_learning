#include <stdio.h>

/* вывод таблицы температур по Фаренгейту и Цельсию
     для celcius = -30, -25, ..., 50;
     версия с вещественной арфиметикой */	
main() {
	float fahr, celcius;
	int lower, upper, step;
	
	lower = -30;	/* нижняя граница темпиратур в таблице */
	upper = 50;	/* верхняя граница */
	step = 5;	/* величина шага */

	printf("  C      F\n");
	printf("----------\n");
	celcius = lower;
	while(celcius <= upper) {
		fahr = celcius * 9.0 / 5.0 + 32;
		printf("%3.0f %6.1f\n", celcius, fahr);
		celcius = celcius + step;
	}
}
