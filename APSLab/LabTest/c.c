#include <stdio.h>
#include <stdlib.h>
int readline( char *str ) {

	char ch;
	int i = 0;
	while ( ( ch = getchar() ) != '\n' ) {
		*str++ = ch;
		i++;
	}
	*str = '\0';
	return i;	
}


int main ( int argc , char * argv[] ) { 

	char * n_ptr;
	char * bin = (char * )  calloc ( 100001 , 1);

	int t = 0 , i = 0;
	long long int divisor = 0;
	long long int dividend = 0;

	scanf("%d%lld" , &t , &divisor );
	getchar();
	i = 0;
	while ( i != t ) {
		i ++;
		readline ( bin );
		dividend = strtoll ( bin , &n_ptr , 2 );
		long long int rem = dividend % divisor;
		if ( rem == 0 )
			printf("Case %d: Yes\n" , i);
		else
			printf("Case %d: No\n" , i);				
	}

	return 0;

}
