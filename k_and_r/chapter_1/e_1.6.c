/* 
 * e_1.6.
 *
 * Status
 *	done
 *
 * Description
 * 	Verify that expression getchr() != EOF is 0 or 1
 * 	contrl + d - is EOF in Linux
 * 	control + z - is EOF in Windows
 */
#include <stdio.h>

main() {
	printf("%d\n", getchar() != EOF);	
}
