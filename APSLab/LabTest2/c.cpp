#include <iostream>
#include <cstdio>
using namespace std;
#define SIZE 1000000
int array[1000010];

int main( int argc , char * argv[] ) {
	char str[16];

	for ( int i = 1 ; i < SIZE ; i++ ) {
		sprintf( str , "%d" , i );
		long long int sum = i;
		for ( int j = 0 ; str[j] != '\0' ; j++ ) {
			sum += (str[j] - '0');
		}
		if ( array[sum] == 1 ) {
			continue;
		}
		else {
			array[sum] = 1;
		}
	}

	for ( int i = 1 ; i < SIZE ; i++ ) {
		//cout << " i : " << i << " " << array[i] << endl;
		if ( array[i] != 1 )
			cout << i << endl;
	}

	return 0;


}
