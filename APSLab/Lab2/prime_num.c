#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000001
#define P_SIZE 700000
int * array , * prime;

int p;
int main( int argc , char * argv[] ) {

	long long int a = 10 , b = 100;
	long long int i , j , t , count = 0;

	array = (int *) calloc ( SIZE , sizeof(int) );
	array[0] = array[1] = 0;

	i = 2;
	while (i < SIZE) {

		if( array[i] == 0 ) {
			count++;
			array[i] = count;
		}
		else {
			array[i] = count;
			i++;
			continue;
		}

		for (j = i * i ; j < SIZE ; j+=i) {
			array[j] = -1;
		}

		i++;
	}

	while ( 1 ) {
		scanf("%lld%lld",&a,&b);

		if(a == 0 && b == 0)
			break;

		if( a > b ) {
			t = a;
			a = b;
			b = t;
		}

		if( a > 1 )
			a--;

		printf("%d\n" , array[b] - array[a]);
	}
	return 0;
}
