/*
Game Of Coins

Pankaj is very fond of collecting coins. There is a game in which he has to collect coins from different counters.
Each counter contain some number of coins.
Pankaj got happy,thinking that he can collect as many coins as possible,but there seems to be a threshold on the number of coins he can collect.
You have to tell Pankaj from how many consecutive counters he can collect coins such that maximum counter are visited without exceeding limit.
Input Specification:

First line consist of T number of testcases.
Next line will contain two integers 'C' 'Max'.
C is the number of counters .
Max is the maximum total coins which can be collected.
Third line contains C integers separated by a single space will denote the  number of coins found in the C-i-th station.
Output Specification:

Your output should consist on T pair of numbers denoting the number of coins Pankaj can collect and the number of counters he will pass respectively.
Constraints:

1<=C<=100,000
1<=Max<=10,000,000
For each counter there will be as much 100 coins

Sample Input:

 
1
5 20
1 4 20 1 2 
Sample Output:

 
5 2\n
Timelimit: 1s
*/
#include <stdio.h>

int main( int argc , char * argv[] ) {

	int t , c , max_coin;
	int array[100001];
	long int sum , i , j , cur_sum , cc;
	long int cur_cc;
	long int max_sum , max_cc;

	scanf("%d" , &t);

	while( t-- ) {

		scanf("%d%d" , &c , &max_coin);
		for( i = 0 ; i < c ; i++ ) {
			scanf("%d" , &array[i]);
		}

                sum = 0;
		cc = 0;
                i = 0;
		cur_sum = 0;
		cur_cc = 0;
		max_cc = 0;
		max_sum = 0;

                for( i = 0 ; i < c ; i++ ) {
			
			cur_sum += array[i];
			cur_cc++;
			//printf("cur_sum = %ld , cur_cc = %ld\n" , cur_sum , cur_cc);
			if( cur_sum <= max_coin ) {
				sum = cur_sum;
				cc = cur_cc;
				//printf("sum = %ld , cc = %ld\n" , sum , cc);
				if( max_cc < cc ) {
					max_sum = sum;
					max_cc = cc;
					//printf("max_sum = %ld , max_cc = %ld\n" , max_sum , max_cc);
				}
				else if( max_cc == cc ) {
					if( sum >= max_sum ) {
						max_sum = sum;
						//printf("max_sum = %ld , max_cc = %ld\n" , max_sum , max_cc);
					}
				}
                        }
			else if ( cur_sum > max_coin ) {
				if( array[i] > max_coin ) {
					continue;
				}

				for( j = cur_cc-1 ; j >= 0 ; j-- ) {
					//printf("Index = j = %d\n" , j);
					cur_sum -= array[i-j];
					cur_cc --;
					//printf("cur_sum = %d and cur_cc = %d\n" , cur_sum , cur_cc);
					if( cur_sum <= max_coin ) {
						//cur_sum += array[i-j];
						//cur_cc ++;
						break;
					}
				}

				//cur_cc = 1;
				//cur_sum = array[i];
				//printf("RESETTING : cursum = %ld , curcc = %ld\n" , cur_sum , cur_cc);
				if( max_cc < cur_cc ) {
					max_sum = cur_sum;
					max_cc = cur_cc;
					//printf("max_sum = %ld , max_cc = %ld\n" , max_sum , max_cc);
				}
				else if ( max_cc == cur_cc ) {
					if( cur_sum >= max_sum ) {
						max_sum = cur_sum;
						//max_cc = 1;
						//printf("max_sum = %ld , max_cc = %ld\n" , max_sum , max_cc);
					}
				}
			}
                }

                printf("%ld %ld\n" , max_sum , max_cc);

	}

	return 0;
}
