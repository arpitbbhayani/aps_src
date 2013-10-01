/*
Trip

Rakesh took APS class students on a trip. Students were unaware, that on the trip Rakesh plans to give them some of the hardest coding problems, they've ever seen, which he has prepared before-hand. But the mistake Rakesh did, is that number of question in each set isn't equal and that might lead to quarrel as every students would probably want to get least number of questions. So he decides to move questions from one set to another so every set contain same no of question.

Input specification

The input consists of several blocks of data. Each block starts with the number of sets of question N(1<= N <=10000) followed by N integers (each less than 1000) in separate lines, giving the number of question in each packet. After the last block of data there is the number -1.

Output specification

The output should contain one line with the smallest number of moves for each block of data.(Followed by a newline character) One move consists of taking one question from a set and putting it into another one. If it is not possible to have the same number of questions in each set, output the number -1.

Example

Sample Input : 
5
1
1
1
1
6
2
3
4
-1
Sample Output : 
4
-1


Timelimit: 1s 
*/

#include <stdio.h>

int eval(int , int * );

int main( int argc , char * argv[] ) {

	int i , j , num , ele[10000] , output[10000] , totalCase = 0;

	do {
		scanf("%d" , &num);
		if(num == -1)
			break;

		totalCase ++;

		for( j = 0 ; j < num ; j++ ) {
			scanf( "%d" , &ele[j] );
		}

		output[totalCase - 1] = eval(num , ele);


	} while (1);

	for( i = 0 ; i < totalCase ; i++ ) {
		printf("%d\n",output[i]);
	}
	return 0;
}

int eval(int num , int * ele) {

	int i , sum = 0 , average = 0;
	float avg = 0.0;
	int count = 0 , check = 0;
	for(i = 0 ; i < num ; i++) {
		sum += ele[i];
	}
	avg = (float) (sum / (float) num);

	average ++;

	if(avg - (int) avg == 0) {
		average = (int) avg;
		for(i = 0 ; i < num ; i++ ) {
			int diff = ele[i] - average;
			//printf(" Checking for element = %d , average = %d\n" , ele[i] , average);
			if(diff > 0) {
				check = check + diff;
				count += diff;
				//printf("Removing from element %d and check = %d\n" , diff , check);
			}
			else if( diff < 0) {

				check = check + diff;
				//count += (-1 * diff);
				//printf("moving into element %d and check = %d\n" , diff , check);
			}
		}
		if(check == 0)
			return count;
		else
			return -1; 
	}
	else {
		return -1;
	}


	return 0;
}
