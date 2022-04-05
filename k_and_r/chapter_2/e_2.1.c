#include <stdio.h>
#include <limits.h>
#include <float.h>

void sh_tsize_stdh_all();
void sh_tsize_char();
void sh_tsize_shrt();
void sh_tsize_int();
void sh_tsize_long();

char get_charmin();
short int get_shrtmin();
int get_intmin();
long int get_longmin();

int main()
{
	printf("Data types ranges.\n");
	printf("Standart headers.\n\n");

	sh_tsize_stdh_all();
	printf("-------------------------------------------------------------------\n\n");

	printf("Data types ranges.\n");
	printf("Direct computation\n\n");

	sh_tsize_char();
	sh_tsize_shrt();
	sh_tsize_int();
	sh_tsize_long();

	return 0;
}

void sh_tsize_stdh_all()
{

	printf("char unsigned range: %d - %d\n", 0, UCHAR_MAX);
	printf("char signed range: %d - %d\n\n", SCHAR_MIN, SCHAR_MAX);

	printf("short unsigned range: %d - %d\n", 0, USHRT_MAX);
	printf("short signed range: %d - %d\n\n", SHRT_MIN, SHRT_MAX);

	printf("int unsigned range: %d - %ld\n", 0, UINT_MAX);
	printf("int signed range: %d - %d\n\n", INT_MIN, INT_MAX);

	printf("long unsigned range: %d - %lu\n", 0, ULONG_MAX);
	printf("long signed range: %ld - %ld\n", LONG_MIN, LONG_MAX);
}

char get_charmin()
{
	char i;
	for (i = 1; i+1 > 0; i = i * 2)
		;
	return i;
}

short int get_shrtmin()
{
	short int i;
	for (i = 1; i+1 > 0; i = i * 2)
		;
	return i;
}

int get_intmin()
{
	int i;
	for (i = 1; i+1 > 0; i = i * 2)
		;
	return i;
}

long int get_longmin()
{
	long int i;
	for (i = 1; i+1 > 0; i = i * 2)
		;
	return i;
}

void sh_tsize_char()
{
	unsigned char uchar;
	char char_min, char_max;
	char_min = get_charmin();
	char_max = char_min-1;
	uchar = 0;
	--uchar;
	printf("char unsigned range: %d - %d\n", 0, uchar);
	printf("char signed range: %d - %d\n\n", char_min, char_max);
}

void sh_tsize_shrt()
{
	unsigned short ushrt;
	short shrt_min, shrt_max;
	shrt_min = get_shrtmin();
	shrt_max = shrt_min-1;
	ushrt = 0;
	--ushrt;
	printf("short unsigned range: %d - %d\n", 0, ushrt);
	printf("short signed range: %d - %d\n\n", shrt_min, shrt_max);
}

void sh_tsize_int()
{
	unsigned int uint;
	int int_min, int_max;
	int_min = get_intmin();
	int_max = int_min-1;
	uint = 0;
	--uint;
	printf("int unsigned range: %d - %ld\n", 0, uint);
	printf("int signed range: %d - %d\n\n", int_min, int_max);
}

void sh_tsize_long()
{
	unsigned long ulong;
	long long_min, long_max;
	long_min = get_longmin();
	long_max = long_min-1;
	ulong = 0;
	--ulong;
	printf("long unsigned range: %d - %lu\n", 0, ulong);
	printf("long signed range: %ld - %ld\n\n", long_min, long_max);
}
