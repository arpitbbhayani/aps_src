/*
Maximum sum sub-rectangle

Given a M × M array of positive and negative integers, find the sub-rectangle with the maximum sum. A sub-rectangle is any
contiguous sub-array of size 1 × 1 or greater located within the whole array. The sum of a rectangle is the sum of all the 
elements in that rectangle. The input to the program is the value of M followed by the array itself. 
Input Specification:
First line contains M ( 1 <= M<= 100 ) 
Next M lines contains M elements each, describing the matrix A ( -100 <= A[i][j] <= 100 )


Output Specification:

The Maximum Sum (Followed by a '\n' which is just for a newline, no need to display)


Sample Input:

 
4
0 -2 -7 0
9 2 -6 2
-4 1 -4 1 
-1 8 0 -2
Sample Output:

15\n
Explanation:

The SubMatrix (1,0)-(3,1) has the maximum sum of 15.
Timelimit: 1s
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int algo ( int *array , int n ) {

/*
	Case 1 : All numbers are negative
	Case 2 : All numbers are positive
	Case 3 : There is a mixture of positive and negative
*/

	int i = 0 , flag_p = 1 , flag_n = 1 , sum = 0 , max = INT_MIN;

	for( i = 0 ; i < n ; i++ ) {

		if( array[i] < 0 ) {
			flag_p = 0;
		}
		else if( array[i] >= 0 ) {
			flag_n = 0;
		}

		sum += array[i];
		if( array[i] > max )
			max = array[i];

	}

	if( flag_p == 1 ) {
		/* All numbers are positive */
		//printf("%d\n" , sum);
		return sum;
	}
	else if( flag_n == 1 ) {
		/* All numbers are negative */
		//printf("%d\n" , max);
		//sum = min;
		return max;
	}
	else {
		/* The numbers are mixed */
		/* sum[i] -> sum till ith element */
		/* array[i] = max( sum[i-1] + array[i] , array[i] ); */

		sum = 0;
		int end = 0 , cur_sum = 0;

		for( end = 0 ; end < n ; end++ ) {
			cur_sum += array[end];
			if( cur_sum > sum ) {
				sum = cur_sum;
			}
			if( cur_sum < 0 ) {
				cur_sum = 0;
			}
		}
		return sum;
	}

	return 0;
}

int main ( int argc , char * argv[] ) {

	int a , i , j , k;
	int **array , *temp ;
	int sum = 0 , max = INT_MIN;

	scanf("%d" , &a);

	array = (int **) malloc( a * sizeof(int*) );
	temp = (int *) malloc( a * sizeof(int) );

	for( i = 0 ; i < a ;i++) {
		array[i] = (int *) malloc( a * sizeof(int) );
	}

	for( i = 0 ; i < a ; i++ ) {
		for( j = 0 ;j < a ;j++ ) {
			scanf("%d" , &array[i][j]);
		}
	}

	for( i = 0 ; i < a ; i++ ) {
		for( k = 0 ; k < a ; k++ )
			temp[k] = 0;
		for( j = i ; j < a ; j++ ) {
			for ( k = 0 ; k < a ; k++ ) {
				temp[k] += array[j][k];
			}
			sum = algo(temp , a);
			if( sum > max )
				max = sum;
		}
	}	
	printf("%d\n" , max);
	return 0;
}
