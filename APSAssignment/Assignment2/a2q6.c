/*The Last Digit


Its time for some maths fun. 
Given two integers p(0<=p<=20) and q(0<=q<=2000000000). 
Find the last digit of p^q. 
Input Specification:
First line contains T i.e number of test cases ( 1 <= T<= 30 ) 
Next T lines contains p and q seperated by space.


Output Specification:

The last digit of p^q.

Sample Input:

 
2
8 2
10 3
Sample Output:

 
4\n
0\n
(\n in the above output represents newline character. This is not an explicit "\n" ) 
Timelimit: 1s
*/


#include <stdio.h>
#include <stdlib.h>

struct node {
	int values[4];
	int size;
};

void populate(struct node *);

int main( int argc , char * argv[] ) {

	struct node array[10];
	int p , a , b;
	long long int q = 0;
	int n;

	populate(array);
	scanf("%d" , &n );

	while( n-- ) {
		scanf("%d%lld" , &p , &q );
		a = p % 10;
		b = q % array[a].size;
	
		if( q == 0) {
			printf("1\n");
			continue;
		}	
		
		if( b == 0 )
			printf("%d\n" , array[a].values[array[a].size - 1]);
		else
			printf("%d\n" , array[a].values[b - 1]);
	
	}

	return 0;
}

void populate(struct node * array) {

	array[0].values[0] = 0;
	array[0].size = 1;

	array[1].values[0] = 1;
	array[1].size = 1;

	array[2].values[0] = 2;
	array[2].values[1] = 4;
	array[2].values[2] = 8;
	array[2].values[3] = 6;
	array[2].size = 4;

	array[3].values[0] = 3;
	array[3].values[1] = 9;
	array[3].values[2] = 7;
	array[3].values[3] = 1;
	array[3].size = 4;


	array[4].values[0] = 4;
	array[4].values[1] = 6;
	array[4].size = 2;

	array[5].values[0] = 5;
	array[5].size = 1;


	array[6].values[0] = 6;
	array[6].size = 1;


	array[7].values[0] = 7;
	array[7].values[1] = 9;
	array[7].values[2] = 3;
	array[7].values[3] = 1;
	array[7].size = 4;


	array[8].values[0] = 8;
	array[8].values[1] = 4;
	array[8].values[2] = 2;
	array[8].values[3] = 6;
	array[8].size = 4;


	array[9].values[0] = 9;
	array[9].values[1] = 1;
	array[9].size = 2;
}


