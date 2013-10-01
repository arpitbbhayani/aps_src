/*
Find the number of binary sequences of length N possible with no consecutive zeroes and
without leading zeroes.
N<=1000000, T<=10
INPUT:
First line contains T, no of test cases
Following T lines contain an integer N (length of binary sequence)
OUTPUT:
Output the number of possible binary sequences for each test case.
Output can be large , so print (output mod 1000000007)
INPUT:
2
2
3
OUTPUT:
2
3
Explanation:
For input 1 , {1} is only possible . So output is 1.
For input 2, {10,11} are possible so output is 2.
For input 3, {101,110,111} are possible so output is 3.

*/

#include <stdio.h>
#include <stdlib.h>
#define BIG_NUM 1000000007
#define SIZE	1000001

int main( int argc , char * argv[] ) {

	long int num = 0 , *array , n = 0 , i = 0;

	array = (long int *) malloc( SIZE * sizeof(long int) );

	array[0] = 1;
	array[1] = 2;

	for(i = 2 ; i < SIZE ; i++ ) {
		array[i] = (array[i-1] + array[i-2]) % BIG_NUM;
	}

	scanf("%ld",&num);

	while( num-- ) {
		scanf("%ld" , &n);
		if( n <= 0 )
			printf("0\n");
		else
			printf("%ld\n" , array[n-1]);
	}

	return 0;
}

