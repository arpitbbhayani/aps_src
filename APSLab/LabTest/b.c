#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000001
int main( int argc , char * argv[] ) {

	int n = 0 , sum = 0 , i = 0 , j = 0;
	int t= 0 ;
	int * array = (int *) calloc ( SIZE , sizeof(int) );

	for ( j = SIZE - 1 ; j > 0 ; j-- ) {
		n = j;

		for( i = 2 ; i * i <= n ; i++ ) {

			if( n % i == 0 ) {
				if( i > (n/i) )
					break;
				if( i == (n/i) ) {
					sum += i;
					break;
				}
				array[i] = 1;
				array[ n / i ] = 1;
			}

		}

	}

	scanf("%d" , &t );

	while ( t-- ) {

		int num = 0;
		scanf("%d" , &num );
		int count = 0;
		for ( i = num ; i >= 2 ; i++ ) {
			if ( array[i] == 1 )
				count++;
		}
		printf("%d" , count );

	}

	return 0;
}
