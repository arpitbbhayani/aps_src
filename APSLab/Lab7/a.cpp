#include <iostream>

using namespace std;

int main ( int argc , char * argv[] ) {

	int n;
	cin >> n;

	int array[n] , max[n];
	int global_max , local_max;

	for ( int i = 0 ; i < n ; i++ ) {
		cin >> array[i];
	}

	if ( n == 0 ) {
		cout << "0" << endl;
		return 0;
	}

	max[0] = 1;
	global_max = 1;

	for ( int i = 0 ; i < n ; i++ ) {

		local_max = 1;

		for ( int j = i-1 ; j >= 0 ; j-- ) {
			if ( max[j] + 1 > local_max && array[i] > array[j] ) {
				local_max = max[j] + 1;
			}
		}

		max[i] = local_max;

		if ( local_max > global_max ) {
			global_max = local_max;
		}

	}

	cout << global_max << endl;

	return 0;

}
