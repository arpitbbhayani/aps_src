/*
Dictionary

Its time to make our own dictionary with 5 letters only.These letters are k,u,m,a,r.
But,this dictionary is different from general english one.
In this 'k' comes before 'u','u' comes before 'm', 'm' comes before 'a', and 'a' comes before 'r'.T

Thus according to our dictionary
1st word is k
2nd word is u
3rd word is m
4th word is a
5th word is r
6th word is kk
7th word is ku

and so on....


You will be given a value of n(1<=n<=10^18).Write the nth word in our dictionary


Input Specification:

First line will contain the number of test cases (t<=100) Next t lines will contain a value n (1<=n<=10^18)


Output Specification:

For each case print the nth word of our dictionary on new line.


Sample Input:

 
Input :

5
1
2
3
10
31

Sample Output:

 

Output 1

k
u
m
kr
kkk


Timelimit: 1s
*/
#include <stdio.h>

int main( int argc , char * argv[] ) {

	int t , b , j;
	long long int n , i;
	int array[100000];

	scanf("%d" , &t);

	while( t -- ) {
		i = 0;
		scanf("%lld" , &n);
		if( n == 0 ) {
			array[i++] = 1;
		}
		while ( n != 0 ) {
			b = n % 5;
			if( b == 0 ) {
				array[i++] = 5;
				n /= 5;
				n--;
				continue;
			}
			else {
				array[i++] = b;
			}
			n /= 5;
		}

		for( j = i-1 ; j >=0 ; j-- ) {
			if( array[j] == 1 )
				printf("k");
			if( array[j] == 2 )
				printf("u");
			if( array[j] == 3 )
				printf("m");
			if( array[j] == 4 )
				printf("a");
			if( array[j] == 5 )
				printf("r");
		}
		printf("\n");

	}

	return 0;
}
