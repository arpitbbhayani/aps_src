#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int _remove ( int * array , int mod , int sum ) {
	if( mod == 1 ) {
		if( array[1] > 0 ) {
			array[1]--;
			sum -= 1;
		}
		else if( array[4] > 0 ) {
			array[4]--;
			sum -= 4;
		}
		else if( array[7] > 0 ) {
			array[7]--;
			sum -= 7;
		}
		else if( array[2] > 1 ) {
			array[2]--;
			array[2]--;
			sum -= 2;
			sum -= 2;
		}
		else if( array[2] > 0 && array[5] > 0 ) {
			array[2]--;
			array[5]--;
			sum -= 2;
			sum -= 5;
		}
		else if( array[5] > 1 ) {
			array[5]--;
			sum -= 5;
			array[5]--;
			sum -= 5;
		}
		else if( array[2] > 0 && array[8] > 0 ) {
			array[2]--;
			array[8]--;
			sum -= 2;
			sum -= 8;
		}
		else if( array[5] > 0 && array[8] > 0 ) {
			array[5]--;
			array[8]--;
			sum -= 5;
			sum -= 8;
		}
		else if( array[8] > 1 ) {
			array[8]--;
			sum -= 8;
			array[8]--;
			sum -= 8;
		}
		else {
			printf("0\n");
			return INT_MIN;
		}
	}
	else {
		if( array[2] > 0 ) {
			array[2]--;
			sum -= 2;
		}
		else if( array[5] > 0 ) {
			array[5]--;
			sum -= 5;
		}
		else if( array[8] > 0 ) {
			array[8]--;
			sum -= 8;
		}
		else if( array[1] > 1 ) {
			array[1]--;
			array[1]--;
			sum -= 1;
			sum -= 1;
		}
		else if( array[1] > 0 && array[4] > 0 ) {
			array[1]--;
			array[4]--;
			sum -= 1;
			sum -= 4;
		}
		else if( array[4] > 1 ) {
			array[4]--;
			sum -= 4;
			array[4]--;
			sum -= 4;
		}
		else if( array[1] > 0 && array[7] > 0 ) {
			array[1]--;
			array[7]--;
			sum -= 1;
			sum -= 7;
		}
		else if( array[4] > 0 && array[7] > 0 ) {
			array[4]--;
			array[7]--;
			sum -= 4;
			sum -= 7;
		}
		else if( array[7] > 1 ) {
			array[7]--;
			sum -= 7;
			array[7]--;
			sum -= 7;
		}
		else {
			printf("0\n");
			return INT_MIN;
		}
	}
	return sum;
}

int main ( int argc , char * argv[] ) {

	int *array;
	int i = 0 , t , n , j;
	long int sum = 0;
	int mod = 0 , flag = 0;

	array = (int *) calloc ( 10 , sizeof(int) );

	scanf("%d" , &t);

	while ( t-- ) {
		scanf("%d" , &n);
		array[n]++;
		sum += n;
		if( n == 0 )
			flag = 1;
	}

	if( flag == 0 ) {
		printf("-1\n");
		return 0;
	}

	mod = sum % 3;

	while( mod != 0 ) {
		if( mod == 1 ) {
			sum = _remove(array , 1 , sum);
		}
		else {
			sum = _remove(array , 2 , sum);
		}
		if( sum == INT_MIN )
			return 0;
		mod = sum % 3;
	}
	
	flag = 0;
	for( i = 9 ; i >= 1 ; i-- ) {
		if( array[i] != 0 )
			flag = 1;
	}

	if( flag == 0 ) {
		printf("0\n");
		return 0;
	}

	for( i = 9 ; i >= 0 ; i-- ) {
		for( j = 0 ; j  < array[i] ; j++ )
			printf("%d" , i);
	}
	printf("\n");

	return 0;

}
