/*
	Find the sum of all numbers between L and U (both inclusive) such that they are divisible
	by a or b.
	As the output can be large,
	print (output )mod (1000000007)
	0<=L<U<=10^8
	1<=a,b<=100
	Input:
		The First line of the input will contain 'T' the number of test cases to be followed. The next
		T lines will contain 4 numbers each (L<space>U<space>A<space>B) where L is the
		lower bound and U is the upper bound. And A and B are the two numbers.
	Output:
		Display the sum of all numbers divisible by A or B between L & U. Output each answer on
		a saperate line.
	Example:
	Input:
		2
		0 10 2 5
		10 20 3 5
	output:
		35
		75
*/

#include <stdio.h>
#include <stdlib.h>
#define BIG_NUM 1000000007

long int eval( long long int , long long int , long long int , long long int );

int main( int argc , char * argv[] ) {
	long long int  l = 0 , u = 0 ;
	long long int a = 0 , b = 0 , n = 0;
	long long int i;
	long int result = 0;

	scanf("%lld" , &n);

	for( i = 0 ; i < n ; i++ ) {
		scanf("%lld %lld %lld %lld" , &l , &u , &a , &b);

		result = eval(l , u , a , b);

		printf("%ld\n" , result );

	}

	return 0;
}

long int eval(long long int l , long long int u , long long int a , long long int b) {

	long long int _l = l , _u = u;
	long long int sum_a = 0 , sum_b = 0 , sum_ab = 0;
	long long int c = 0 , _a = a , _b = b , lcm = 1;
	long long int sum_u_l , sum_u_b;
	if( a > b ) {
		c = a;
		a = b;
		b = c;	
	}

	if( l % a != 0)
		_l = l + (a - (l % a));
	else
		_l = l;

	_u = u - (u % a);

	if( a > _u )
		return 0;

	if ( a == 1 ) {
		sum_u_l = l * ( l + 1) / 2;
		sum_u_b = u * ( u + 1) / 2;
		return (sum_u_b - sum_u_l + l) % BIG_NUM;
	}

	if( _u >= _l )
		sum_a = ((((_u - _l)/(a) + 1) * ( _l + _u )) / 2);
	

	//printf("_l = %ld , _u = %ld , suma = %ld\n" , _l , _u , sum_a);

	if( b % a == 0 || b > _u )
		return sum_a % BIG_NUM;

	if( l % b != 0)
		_l = l + b - (l % b);
	else
		_l = l;
	
	_u = u - (u % b);

	if( _u >= _l )
		sum_b = ((((_u - _l)/(b) + 1) * ( _l + _u )) / 2);

	//printf("_l = %ld , _u = %ld , sumb = %ld\n" , _l , _u , sum_b);
	
	while( _a != _b ) {
		if ( _a > _b )
			_a = _a - _b;
		if( _b > _a )
			_b = _b - _a;
	}

	lcm = (a * b) / _a;
	
	if( l % (lcm) != 0 )
		_l = l + (lcm) - (l % (lcm));
	else
		_l = l;
	_u = u - (u % (lcm));

	if( _u >= _l )
		sum_ab = ((((_u - _l)/(lcm) + 1) * ( _l + _u )) / 2);

	//printf("_l = %ld , _u = %ld , sumab = %ld\n" , _l , _u , sum_ab);
	
	return ((sum_a + sum_b - sum_ab) % BIG_NUM);
}
