#include<stdio.h>
#include<stdlib.h>
#define BIG_NUM 1000000007
#define SIZE 1002

int main() {

	int n , m ;
	int i , j;
	long int array[SIZE][SIZE];

	for( i = 0 ; i < SIZE ; i++ ) {
		array[0][i] = 1;
		array[i][0] = 1;
	}

	for( i = 1 ; i < SIZE ; i++ ) {
		for( j = 1 ; j < SIZE - i ; j ++ ) {
			array[i][j] = (array[i-1][j] + array[i][j-1])% BIG_NUM;
		}
	}

	for( i = 0 ; i < SIZE ; i++ ) {
		for( j = 0 ; j < SIZE - i ; j ++ ) {
			//printf("%ld " , array[i][j]);
		}
		//printf("\n");
	}

	while ( 1 ) {
                scanf("%d%d" , &n,&m);
                if( n == -1 && m == -1 )
                        break;		

		printf("%ld\n" , array[ n - m ][m]);

	}

	return 0;
}
