/*
Co-primes

Time to check your math aptitude.

Two numbers are relatively co-primes if their greatest common divisor is 1. For example, gcd(14,15) =1. Given M and N as input, Write a program to tell whether they are co-primes or not.

Constraints:


M <= 10^8 and N <= 10^8
Input Specification:

The input format is: M(space)N. End of the input would be determined when both M and N are zero.

Output Specification:

Print "Yes" if number are relatively prime, otherwise "No".(Without quotes). Followed by a newline character. 

Sample Input

3 4
5 10
14 15
0 0
Sample Output

Yes
No
Yes
*/

#include <stdio.h>

int getGcd(int, int);

int main( int argc , char * argv[] ) {
	
	int m , n , gcd = 0;

	do {

		scanf("%d %d" , &m , &n);
		if( m == 0 && n == 0)
			break;
		gcd = getGcd(m,n);
		if( gcd == 1 )
			printf("Yes\n");
		else
			printf("No\n");
	} while (1);
	return 0;
}

int getGcd(int a , int b) {
	while( a != b ) {
		if( a > b )
			a = a - b;
		if( b > a )
			b = b - a;
	}
	return a;
}

