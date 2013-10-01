/*
Here is a very easy linear recurrence for you to solve,
F(k) = 2.F(k-1) + 5.F(k-2) + 3
Initial Cases: F(0) = 1, F(1) = 2.
Input: Given n and M
Constraints: 0 <= n <= 10^9 , 2 <= M <= 10^9
Output: find the value of F(n) % M
Sample Case:
1)
Input:
4 15
Output:
2\n
2)
Input:
3 40
Output:
37\n
*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 3

long long int multiply ( long long int ** , long long int ** , long long int );

int main( int argc , char * argv[] ) {
	long long int m , n , i , sum = 0 ;
	long long int ** array1 , **array2;

	scanf("%lld%lld", &n , &m);

	if( n == 0 ) {
		printf("1\n");
		return 0;
	}

	array1 = (long long int **) malloc ( SIZE * sizeof(long long int *) );

	for( i = 0 ; i < SIZE ; i++ ) {
		array1[i] = (long long int *) malloc ( SIZE * sizeof(long long int));
	}

	array1[0][0] = 2;	array1[0][1] = 5;	array1[0][2] = 1;	array1[1][0] = 1;
	array1[1][1] = 0; 	array1[1][2] = 0;    	array1[2][0] = 0;    	array1[2][1] = 0;
	array1[2][2] = 1;

	array2 = (long long int **) malloc( SIZE * sizeof(long long int *) );
	for( i = 0 ; i < SIZE ; i++ ) {
		array2[i] = (long long int *) malloc ( SIZE * sizeof(long long int) );
	}

	array2[0][0] = 1;	array2[0][1] = 0;	array2[0][2] = 0;	array2[1][0] = 0;
	array2[1][1] = 1;	array2[1][2] = 0;	array2[2][0] = 0;	array2[2][1] = 0;
	array2[2][2] = 1;

       	n--;

	while( n > 0 ) {

		if( n % 2 == 1 )
			multiply( array2 , array1, m );

		multiply( array1 , array1 , m );

		n /= 2;
	}

	sum = ( array2[0][0] * 2 + array2[0][1] * 1 + array2[0][2] * SIZE) % m;
  
	printf("%lld\n",sum); 

	return 0;
}

long long int multiply ( long long int ** array2 , long long int ** array1 , long long int m ) {

	long long int ** temp = (long long int **) malloc ( SIZE * sizeof(long long int * ) );
	int i , j , k ;

	for( i = 0 ; i < SIZE ; i++ ) {
		temp[i] = (long long int *) malloc ( SIZE * sizeof(long long int));
	}

	for( i = 0 ; i < SIZE ; i++ ) {
		for( j = 0 ; j < SIZE ; j++ ) {

			temp[i][j] = 0;

			for( k = 0 ; k < SIZE ; k++ ) {
				temp[i][j] += (( array2[i][k] * array1[k][j] ) % m);
			}
		}
	}

	for( i = 0 ; i < SIZE ; i++ ) {
		for( j = 0 ; j < SIZE ; j++ ) { 
			array2[i][j] = temp[i][j];
		}
	}

	return 0;
}
