/*
*	Write a program to calculate the sum of digits of the expression 2^X where x is between 1
*	and 1000. The value of X is given as input. For example, 2^7=128, sum of digits=1+2+8=11.
*	Example
*		INPUT:
*			7
*			4
*			-1
*		OUTPUT:
*			11
*			7
*/

/*
	Store first base number in an array and then do operation on it . at the end sum all the numbers.
	i.e. implement myinteger with multiplication.
*/

#include <stdio.h>
#include <stdlib.h>

long int sodIn2x(int);
//void printDigits(char *);

int main( int argc , char * argv[] ) {

	int n = 0;

	while( 1 ) {
		scanf("%d", &n);
		if( n == -1 )
			break;
		
		printf("%ld\n" , sodIn2x(n));

	}

	return 0;
}

long int sodIn2x(int n) {

	long int sum = 0;
	int i = 0;
	char carry = '0' , temp;
	char * digits = (char *) malloc ( 17000  * sizeof(char) );
	char * ptr = digits;

	digits[0] = '2';
	digits[1] = 'a';
	
	for( i = 1 ; i < n ; i++ ) {

		ptr = digits;

		while( *ptr != 'a' ) {

			temp = *ptr;

			(*ptr) = ((2 * ((temp) - '0') + (carry - '0')) % 10) + '0';
			(carry) = ((2 * ((temp) - '0') + (carry - '0')) / 10) + '0';
			
			ptr++;
		}
		if( carry == '1' ) {
			*ptr = '1';
			ptr ++;
			*ptr = 'a';
			carry = '0';
		}

	}	

	ptr = digits;
	while( (*ptr) != 'a' )
		sum += (*ptr++)-'0';

	//printDigits(digits);
	free(digits);

	return sum;
}

/*void printDigits ( char *str ) {
	int i = 0;
	printf("Array : ");
	while ( 1 ) {
		if(str[i] == 'a') {
			printf("\n");
			return;
		}
		printf("%c" , str[i]);
		i++;
	}
}*/
