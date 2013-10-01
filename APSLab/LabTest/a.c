#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int (compar)(const void *a, const void *b) {
	int x = *((int *) (a));
	int y = *((int *) (b));
	return x-y;
}

int main ( int argc , char * argv[] ) { 

	int t , i;
	int array[4];
	scanf( "%d" , &t );

	while ( t-- ) {
		for ( i = 0 ; i < 4 ; i++ ) {
			scanf("%d" , &array[i] );
		}

		qsort ( array , 4 , sizeof(int ) , compar );

		printf("%d\n" , array[3] + array[2] );

	}
	return 0;

}
