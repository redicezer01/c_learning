/*
 * e_1.2.
 * 
 * Status
 *	done
 *
 * Description
 *	Experiment with \c, where c some character
 */
#include <stdio.h>

main() {
	printf("hello");
	printf("\f");
	printf("world!\n");
}

/*
 * \a - nothing
 * \c - unknown escape sequence
 * \d - unknown escape sequence
 * \e - deletes next symbol
 * \f - s next symbol
 */
