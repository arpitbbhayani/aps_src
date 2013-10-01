#include <stdio.h>
#include <stdlib.h>

#define BIG_NUM 1000000007

long int eval(long long int);

int main( int argc , char *argv []) {

	long long int n;

	while ( 1 ) {
		scanf("%lld" , &n);
		if( n == 0 )
			break;
		eval(n);
	}

	return 0;
	
}

long int eval( long long int n) {
	long long int i = 1;
	long long int sum = 0;
	//long long int pro = 0;
	long long int k=1;

	for(i = 1 ; i <= n ; ) {
		k++;
		sum = (sum + i)%BIG_NUM;
		i=k*k;
	}
	printf("%lld %lld\n" , k-1 , sum);
	return (0);

}
