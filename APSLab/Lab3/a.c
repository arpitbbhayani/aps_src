/*Light Bulb

Given a grid of lights(R X C), our goal is to turn on all the lights. 1 = on, 0 = off.
Flipping a blub means, changing its state ( from on to off, or off to on ). 
If we flip a bulb(i,j), all the bulbs in a matrix consisting of rows [0..i] and columns [0..j] also get flipped.

eg:
0 1 1 0
0 0 * 1
0 1 0 1
1 1 0 1

lets say bulb (1,2), marked as * is actually 0 and if you flip it the grid becomes

1 0 0 0
1 1 1 1
0 1 0 1
1 1 0 1

(i.e., all (0,0) to (i,j) flipped ).

Objective : You have to turn on all lights using minimum flips.
Input Specification:

First line contains R(1<=R<=100) and C(1<=C<=100) 
following line contains the matrix(R X C) input

Output Specification:

Print the answer in a single line, followed by a '\n' ( just print a new line, no need to display '\n' )

Constraints:

1 <= R,C <= 100


Sample Input:

 
Input 1

2 3
1 1 1
1 0 1

Input 2

3 3
1 1 1
0 0 0
0 0 0
Sample Output:

 

Output 1

4\n

Output 2

2\n

Timelimit: 1s
*/
#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char * argv[] ) {

	int m , n , flag , i , j;
	int count = 0;
	int k , l;
	int **array;

	scanf("%d%d" , &m , &n);

	array  = (int **) malloc ( m * sizeof(int *) );

	for( i = 0 ; i < m ; i++ ) {
		array[i] = (int *) malloc( n * sizeof(int) );
	}

	for( i = 0 ; i < m ; i++ ) {
		for ( j = 0 ; j < n ; j++) {
			scanf("%d" , &array[i][j]);
		}
	}
	flag = 0;
	count = 0;
	for( i = m-1 ; i>= 0 ; i-- ) {
		if( flag == 1 ) {
			for( j = 0 ; j < n ; j++ ) {
				if(array[i][j] == 0) {
					count++;
					for( k = 0 ; k <= i ; k++ ) {
						for(l = 0 ; l <= j ;l++) {
							if(array[k][l] == 0 )array[k][l] = 1;
							else			array[k][l] = 0;
						}
					}
				}
			}
		}
		else {
			for( j = n-1 ; j>=0 ; j-- ) {
				if(array[i][j] == 0) {
					count++;
					for( k = 0 ; k <= i ; k++ ) {
						for(l = 0 ; l <= j ;l++) {
							if(array[k][l] == 0 )array[k][l] = 1;
							else			array[k][l] = 0;
						}
					}
				}
			}
		}
		flag = 0;


	}
	printf("%d\n" , count);

	return 0;
}
