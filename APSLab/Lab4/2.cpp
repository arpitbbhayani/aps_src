/*
Game of Thrones

Bran Stark wants Hodor to learn problem solving. The first problem he gave is as following 

"Given an array of numbers print the next greater number for every number.
The Next greater number for a number n is the first greater number on the right side of n in array.
Numbers for which no greater number exist, consider next greater number as -1."

We all know that Hodor knows nothing except calling his own name. You need to help him to solve this problem.

INPUT 
The first line of the input contains an integer N denoting the number of elements in the given array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the given array. 

OUTPUT 
Print the array with each number replaced by its next greater number.

CONSTRAINTS
1 ≤ N ≤ 10^6	
0≤ Ai ≤ 10^8 

SAMPLE	

Input
5
10 4 15 6 21
Output
15 15 21 21 -1 \n

Input
7
3 0 8 8 5 29 12
Output
8 8 29 29 29 -1 -1 \n

Timelimit: 1s
*/

#include <stdio.h>
#include <iostream>
#include <map>
#include <stack>

using namespace std;

	int array[1000000];
struct node {
	int val;
	int index;
};

int main( int argc , char *argv[] ) {
  
	int t = 0;
	int i , temp;

	stack<struct node> s;

	scanf("%d" , &t);

	scanf("%d" , &temp);
	struct node n;
	n.val = temp;
	n.index = 0;
	s.push(n);

	for( i = 1 ; i < t ; i++ ) {
		scanf("%d" , &temp);

		struct node a;
		a.val = temp;
		a.index = i;

		if( !s.empty() ) {
		while( s.top().val < temp ) {
			array[s.top().index] = temp;
			
			s.pop();
			if( s.empty() ) 
				break;
		}
		}
		s.push(a);

	}

	while ( !s.empty() ) {
		array[s.top().index] = -1;
		s.pop();
	}	
	for( i = 0 ; i < t  ; i++ ) {
		printf("%d " , array[i]);
	}
	printf("\n");
	return 0;
}
