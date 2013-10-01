#include <stdio.h>
#include <stdlib.h>

int merge ( int * array , int l , int m , int h ) {

	int b_array[100001];
	int i = 0 , j = 0 , k = 0;
	int count = 0;

	i = k = l;
	j = m+1;
	while ( i <= m && j <= h ) {
		if ( array[i] <= array[j] ) {
			b_array[k++] = array[i++];
		}
		else {
			count += ( m - i + 1 );
			b_array[k++] = array[j++];
		}

	}
	if ( i > m ) {
		while ( j <= h ) {
			b_array[k++] = array[j++];
		}
	}
	else if ( j > h ) {
		while ( i <= m ) {
			b_array[k++] = array[i++];
		}
	}

	k = l;

	while ( k <= h ) {
		array[k] = b_array[k];
		k++;
	}
	return count;
}

int count_inv ( int * array , int start , int end ) {


	if ( start >= end ) return 0;

	int mid = (start + end ) / 2;

	int count_l = count_inv ( array , start , mid );

	int count_r = count_inv ( array , mid+1 , end );

	int count_m = merge ( array , start , mid , end );

	return count_l + count_r + count_m;
}

int main ( int argc , char * argv[] ) {

	int t , n , i;
	int *array;

	scanf("%d" , &t);

	while ( t-- ) {

		scanf("%d" , &n);
		array = (int *) malloc ( n * sizeof(int) );

		for ( i = 0 ; i < n ; i++ ) {
			scanf("%d" , &array[i]);
		}
		printf("%d\n" , count_inv( array , 0 , n-1 ) );

		free(array);
	}

	return 0;
}
