/*
Given an array A, you now know how to find a Sub-Array sum i.e., A[i]+ A[i+1] + ... + A[j]. A
sub-array is defined by its starting index i and its ending index j ( 0 <= i <= j < N ). Can you find
the maximum sum of a sub-array.
Input:
First line contains N, number of elements in the array ( 1 <= N <= 100000 ).
Second line contains N integers in range [-10^4,10^4], separated by spaces.
Output:
Print the maximum sum possible for a sub-array of A. (Followed by a '\n' which is just for a
newline, no need to display)
Sample Cases:
Input:
4
1 -2 1 2
Output:
3\n
Explanation:
Sum(0..0) = 1, Sum(0..1) = -1, Sum(0..2) = 0, Sum(0..3) = 2, . . . , Sum(2..3) = 3, . . . , Sum(3,3) = 2
Among all possible SubArray sums, Sum(2..3) = 3 has the maximum value.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main( int argc , char * argv[] ) {

/*
	Case 1 : All numbers are negative
	Case 2 : All numbers are positive
	Case 3 : There is a mixture of positive and negative
*/

	int n;
	int * array = NULL;

	int i = 0 , flag_p = 1 , flag_n = 1 , sum = 0 , max = INT_MIN;

	scanf("%d" , &n);

	array = (int *) malloc ( n * sizeof(int) );

	for( i = 0 ; i < n ; i++ ) {
		scanf("%d" , &array[i]);

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
		printf("%d\n" , sum);
		return 0;
	}
	else if( flag_n == 1 ) {
		/* All numbers are negative */
		printf("%d\n" , max);
		//sum = min;
		return 0;
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
		printf("%d\n" , sum);
	}


	return 0;
}
