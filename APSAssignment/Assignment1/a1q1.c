/*
*	 Given a natural number n (1 <= n <= 500000), output the summation of all its proper divisors. 
*	A proper divisor of a natural number is the divisor that is strictly less than the number. 
*	For example 20 has 5 proper divisors: 1, 2, 4, 5, 10, and the divisor summation is:
*	1 + 2 + 4 + 5 + 10 = 22.
*	Example:
*		Input:
*			20
*			6
*			8
*			-1
*		Output:
*			22
*			6
*			7
*/

#include <stdio.h>
#include <stdlib.h>

int main( int argc , char * argv[] ) {

	int n = 0 , sum = 0 , i = 0;

	while ( 1 ) {
		scanf("%d" , &n);

		
		if( n == 1 ) {
			printf("0\n");
			continue;
		}


		if( n == -1 )
			break;

		sum = 0;

		for( i = 2 ; i * i <= n ; i++ ) {

			if( n % i == 0 ) {
				if( i > (n/i) )
					break;
				if( i == (n/i) ) {
					sum += i;
					break;
				}
				sum += i;
				sum += (n / i);
			}

		}
		sum = sum + 1;
		printf("%d\n" , sum);

	}

	return 0;
}
