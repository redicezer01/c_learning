/*
 * e_4.3.
 *
 * Status
 *	done	
 *
 * Description
 *	Given the basic framework, it's straightforward to extend the
 *	calculator. Add the modulus operator (%) and provisions for
 *	negative numbers.
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char s[]);
void push(double);
double pop(void);

/* calculator reverse Polish notatio */
int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: sero devisor\n");
			break;
		/* added modulus operator */
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push((long long int) pop() % (long long int) op2);
			else
				printf("error: sero devisor\n");
			break;
		case '\n':
			printf("\t%.8f\n", (double) pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}

	return (0);
}

#define MAXVAL 100

int sp;
double val[MAXVAL];	/* value stack */

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0) {
		return val[--sp];
	} else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if (!isdigit(c) && c != '.' && c != '-')
		return c;
	/* negative number support */
	else if (c == '-') 
		s[++i] = c = getch();
	
	/* negative number support */
	if (s[0] == '-' && c != '.' && !isdigit(c)) {
		ungetch(c);
		return '-';	
	}

	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;	
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

/* get a (possibly pushed back) character. */
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
