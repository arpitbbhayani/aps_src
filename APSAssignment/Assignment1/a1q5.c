/*
	Kabeer has a diamond rod which is “n” meter long. He lost a bet with Pankaj so he is
	required to pay 1 meter of that rod to Pankaj everyday for “n” days. As cutting a rod is
	very difficult and Kabeer is very lazy, he wants to minimize his efforts for cutting the rod.
	Kabeer realized that it was not necessary to cut exactly 1m rod everyday. For example, on
	the third day, he can give a 3 meter rod and can have 2 meter rod back which pankaj has
	already taken from him. Can you help your TA to minimize his efforts by telling the
	minimum cuts required so that he can pay from 1st to nth day to make his daily payment
	of 1m rod.
	At the end of nth day he would have given the whole rod to Pankaj.
	Input
		Input would be a positive integer denoting the length of the rod(as well as no of days). 0 <
		n < 1000000. Terminate your program by a 0.
	Output
		For each “n” print the minimum number of cuts required so that Kabeer can fulfill his bet
		by paying 1 meter daily.
	Example
	Input:
		3
		5
		1
		0
	Output:
		1
		2
		0
*/

#include <stdio.h>
#include <stdlib.h>

int eval(int);

int main(int argc , char * argv[]) {

	int n , result;

	while( 1 ) {
		scanf("%d" , &n);
		if ( n == 0 )
			break;
		result = eval(n);
		printf("%d\n" , result);
	}
	
	return 0;
}

int eval(int n) {
	int c = 0;
	while(n) {
		c++;
		n = n >> 1;
	}
	return c-1;
}
