/*Matrix sum

You will be given a matrix A of size m*n .

Your task is to find sum of all the numbers(which can be negative as well) between two corners(north-west and south-east).

Input Specification:

3 integers in first line : m,n,t
where m*n is the size of matrix
and t is the number of test cases.

Next m lines contains n integers(which can be negative).

After that,next t line will follow 4 integers x1,y1,x2,y2 where (x1,y1) is the coordinates of north-west and (x2,y2) is the coordinates of south-east corners.
Output Specification:

One line denoting the sum of the numbers between the two given corners.

Constraints:

1<=m,n<=1000

1<=t<=5000

1<=x1<=x2<=1000 
1<=y1<=y2<=1000
-1000<=a[i][j]<=1000

Sample Input:

 
Input 1

3 3 1
1 2 3
4 5 6
7 8 9
1 1 2 2

Sample Output:

 

Output 1

12\n

Timelimit: 1s
*/
#include <stdio.h>
#include <stdlib.h>

int main( int argc , char * argv[] ) {

	int m , n , t , test;
	int i , j;
	int  ** array = NULL;
	int a,b,c,d;
	int total = 0;

	scanf("%d%d" , &m , &n);

	array = (int **) calloc( m , sizeof(int*) );

	for( i =0 ; i < m ;i++ ) {
		array[i] = (int *) malloc( n * sizeof(int));
	}

	scanf("%d" , &test);

	for( i = 0 ; i < m ; i++) {
		total = 0;
		for( j = 0 ; j < n ; j++ ) {
			scanf("%d" , &t);
			total += t;
			array[i][j] = total;
		}
	}

	while( test-- ) {
		scanf("%d%d%d%d" , &a , &b , &c , &d);
		a--;b--;c--;d--;
		if ( d > n )
			d = n - 1;
		if( c > m )
			c = m - 1;
		if( a < 0 )
			a = 0;
		if( b < 0 )
			b = 0;
		total = 0;
		for( i = a ; i <= c ; i++ ) {
			if( b > 0 )
				total += (array[i][d] - array[i][b-1]);
			else
				total += (array[i][d]);
		}

		printf("%d\n" , total);

	}

	return 0;
}
