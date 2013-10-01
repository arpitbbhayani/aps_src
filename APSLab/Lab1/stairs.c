/*
Rishit didn't prepare any question for the APS lab. So while coming to teaching lab in Nilgiri building when he saw the staircase, he came up with one of his wonderful questions. He can move up either 1 or 2 stairs at a time, as he's afraid of jumping more than 2 stairs at a time.
Given the no of stairs, you should tell Rishit the number of ways he can reach the top. Initially he is standing on ground.

Constraints:

1 <= n <= 1000000 , 1 <= t <= 10

Input:

First line contains t, number of testcases. Next t lines contain value of n (number of stairs)

Output:

Output the result for test case.(Number of ways you can reach top of Staircase). Followed by a newline character.
As the result can be large , print ( output mod 1000000007 )

Example:

Input:
  2
  1
  2
Output:
  1
  2
 
Timelimit : 1s
*/

#include <stdio.h>

#define BIG_NUM 1000000007

long int eval(int);

int main( int argc , char * argv[] ) {

	long int num = 0 , array[10000] , stair = 0 , i = 0;

	scanf("%ld",&num);

	for(i = 0 ; i < num ; i++ ) {
		scanf("%ld",&stair);
		array[i] = eval(stair);
	}

	for(i = 0 ; i < num ; i++) {
		printf("%ld\n",array[i]);
	}
	
	return 0;
}

long int eval(int n) {

	long int f1 = 1 , f2 = 2 , f = 0;

	if( n == 1 )
		return f1;
	if ( n == 2 ) 
		return f2;

	while( n > 1 ) {
		f = (f1 + f2) % BIG_NUM;
		f1 = f2 % BIG_NUM;
		f2 = f % BIG_NUM;
		n--;
	}

	return f1;
}
