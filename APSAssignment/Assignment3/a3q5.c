#include <stdio.h>
#include <stdlib.h>

int main( int argc , char * argv[] ) {

	int t ;

	int * array1 , * array2;

	scanf("%d" , &t);

	while( t-- ) {

		int num , index1 , index2;
		int i = 0;
		int count = 0 , t_count = 0;

		scanf("%d" , &num );
	
		array1 = (int *) malloc ( num * sizeof(int) );
		array2 = (int *) malloc ( num * sizeof(int) );
 
		for( i = 0 ; i < num ; i++)
			scanf("%d" , &array1[i] );
			
		for( i = 0 ; i < num ; i++)
			scanf("%d" , &array2[i] );

		index1 = index2 = num - 1 ;

		for( i = 0 ; i < num ; i++ ) {
			if( array1[ index1 ] == array2[ index2 ] ) {
				count += t_count;
				t_count = 0;
				index2--;
			}
			else {
				t_count++;
			}
			index1--;				
		}

		count += t_count;
		printf("%d\n" , count );

		free ( array1 );
		free ( array2 );

	}
	return 0;
}
