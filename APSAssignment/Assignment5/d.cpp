#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int main ( int argc ,char * argv[] ) {

	int t;
	scanf("%d" , &t);

	map< long long int , long long int > sum_p;
	map< long long int , long long int>::iterator itr;

	while ( t-- ) {


		long long int count = 0;
		long long int n;

		scanf("%lld" , &n);

		long long int array[n];

		scanf("%lld" , &array[0]);

		sum_p[ array[0] ] ++;

		for ( int i = 1 ; i < n ; i++ ) {
			scanf("%lld" , &array[i]);
			array[i] += array[i-1];
			sum_p[ array[i] ] ++;
		}


		for ( itr = sum_p.begin() ; itr != sum_p.end() ; itr++ ) {
			long long int a,b;

			a = itr->first;
			b = itr->second;

			if ( a != 0 ) {
				count += b * (b-1) / 2;
			}
			else {
				count += b + (b * (b-1)/2 );
			}
		}

		printf("%lld\n" , count);
		sum_p.clear();
	}

	return 0;

}
