#include <stdio.h>
#include <string.h>

/*
	Eg : for 798
	7 -> 1 -> 1 * 3 ^ (3-1) -> 9
	9 -> 2 -> 2 * 3 ^ (2-1) -> 6
	8 -> 2 -> 2 * 3 ^ (1-1) -> 2
	Ans = 17 + uptill 100 = 17 + 12 = 29

	For number starting with non lucky digits :
	change number to <lucky_digit>0000000.....
*/

int lesser[] = { 0 , 0 , 0 , 0 , 1 , 1 , 1 , 1 , 2 , 2  };
long long int _power[16];

int main ( int argc , char * argv[] ) {

	long long int n;
	char num[64];

	long long int count = 0;
	long long int i = 0;

	int lucky = 1;

	_power[0] = 1;
	for ( i = 1 ; i < 16 ; i++ ) {
		_power[i] = _power[i-1] * 3;
	}

	scanf("%lld" , &n );

	while ( n != 0 ) {

		count = i = 0;

		sprintf(num , "%lld" , n );
		int num_of_digits = strlen( num );

		count = ( (_power [ num_of_digits ] - 1 ) / 2 ) - 1 ;

		
		for ( i = 0 ; num[i] != '\0' ; i++ ) {
			if ( num[i] != '3' && num[i] != '7' && num[i] != '9' ) {
				break;
			}
		}
		if ( num[i] != '\0' ) {
			for ( i = i + 1 ; num[i] != '\0' ; i++ ) {
				num[i] = '0';
			}
		}

		//printf("Number = %s\n" , num);

		lucky = 1;

		for ( i = 0 ; num[i] != '\0' ; i++ ) {

			count += ( lesser[num[i] - '0'] * _power [num_of_digits - 1 - i] );
			if ( num[i] != '3' && num[i] != '7' && num[i] != '9' ) {
				lucky = 0;
			}
		}

		if ( lucky == 1 ) {
			count++;
		}

		printf("%lld\n" , count);
		scanf("%lld" , &n );

	}

	return 0;
}
