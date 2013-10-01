#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000001

int main ( int argc , char *argv[] ) {

	//int * array = (int *) calloc ( SIZE , sizeof(int )) ;
	int i , t ,a;

	scanf("%d" , &t);

	while ( t-- ) {
		scanf("%d" , &i );
		a= 0;
		if ( i & 1 )
			a++;
		a += (i>>1);

		printf("%d\n" , a);
	}

	return 0;
}
