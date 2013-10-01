#include <stdio.h>
#include <stdlib.h>

#define BIG_NUM 1000000007

long int *factorial;

long int ncr ( int , int );
long int getFactorial(int);
long int getInverse(long int);

int main ( int argc , char * argv[] ) {

	int n , m ;
	long int result = 0;

	factorial = (long int *) calloc(1001 , sizeof(long int));

	factorial[0] = factorial[1] = 1;

	while ( 1 ) {
		scanf("%d%d" , &n,&m);
		if( n == -1 && m == -1 )
			break;

		if ( n < m ) {
			printf("%ld\n" , (long int)0);
			continue;
		}

		if ( n == m) {
			printf("%ld\n" , (long int) 1);
			continue;
		}
	
		if ( m == 0) {
			printf("%ld\n" , (long int) 1);
			continue;
		}

		if ( n == 0 ) {
			printf("%ld\n" , (long int)0);
			continue;
		}

		////printf("For n = %d and r = %d\n" , n , m);
		if( m > (n-m) ) {
			////printf("Evaluating: n = %d and r = %d\n" , n , n-m);
			result = ncr(n,n-m);
		}
		else {
			////printf("Evaluating: n = %d and r = %d\n" , n , m);
			result = ncr(n,m);
		}

		printf("%ld\n", result);

	}

	free(factorial);
	return 0;
}

long int ncr ( int n , int r ) {

	long int _n = 1 ;
	long int _r = 1 ;
	long int _nr = 1 , _d = 1;

	_n = getFactorial(n);
	_r = getFactorial(r);
	_nr = getFactorial(n-r);

	_d = getInverse( (_r * _nr)% BIG_NUM );

	//printf("INverse of %ld is %ld\n", (_r*_nr) % BIG_NUM , _d);

	return (_n * _d)%BIG_NUM;
	//return (_n)%BIG_NUM;

}

long int getInverse(long int n) {
    long int ex = BIG_NUM-2, result = 1;
    while (ex > 0) {
        if (ex % 2 == 1) {
            result = (result*n) % BIG_NUM;
        }
        n = (n*n) % BIG_NUM;
        ex /= 2;
    }
    return result;

}

long int getFactorial(int n) {

	int i = 0;

	//printf("In Factorial : n = %d and factorial(n) = %ld\n", n , factorial[n]);

	if( factorial[n] ) {
		return factorial[n];
	}

	//printf("Factorial does not exist for n = %d\n", n);
	for( i = n - 1 ; i >= 1 ; i-- ) {
		if( factorial[i] != 0 )
			break;
	}
	//printf("Factorial available for n = %d\n", i);

	for( ; i <= n ; i++) {
		factorial[i] = (factorial[i-1] * i) % BIG_NUM;
		//printf("Evaluating factorial for n = %d using fact(i-1) = %ld and answer = %ld\n" , i , factorial[i-1] , factorial[i]);
	}

	return factorial[n];
}
