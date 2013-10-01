/*
Bracket Stabling

No fancy story for this one.
You would be given a string of curly braces i.e either an opening brace '{' or a closing bracket '}'.
 Which may or may not be stable. The definition of a stable string is:
	
	a. A NULL string is stable.
	b. If a string str is stable so would be {str}
	c. If two strings are stable than their concatenation would also be stable
i.e. if str1 and str2 is stable then str1str2 is also stable.
	
Some examples of Stable strings: {{}}, {}{} and {}
Some examples of Un-Stable strings: {{ , }{ and {{}{

You have to tell minimum number of actions needed to make a string stable.
An action is to either replace an opening brace with a closing or vice-versa.

Input Specification:

There would be multiple test cases. Each line would be containing one input string.
Each line/string would be a non-empty string
and would be composed of only opening and closing braces '{' and '}' only.
Any string can contain atmost 2000 braces and would be even in length.
Last line would be containg one or more minus sign(-)
your program should not process beyond that.
Output Specification:

For every input line you have to print the following line :

n.(space)A

where 'n' is the test case no (starting from 1) followed by a dot(.) then a single space 
and the number of actions needed to make input string stable.
Print a new-line character (\n) after each line.


Sample Input:

 

{{}{
{{
{}
----
Sample Output:

 

1. 1
2. 1
3. 0
*/

#include <stdio.h>
char stack[10000];
int top;

int readline( char *str ) {
        char ch;
	int i = 0;
        while ( ( ch = getchar() ) != '\n' ) {
                *str++ = ch;
		i++;
	}
        *str ='\0';
        return i;
}
void eval( int n , char * array , int l) {

	int ans = 0;
	top = -1;
	int i = 0;
	for( i = 0 ; i < l ; i++ ) {
		if( array[i] == '{' ) {
			top++;
			stack[top] = '{';
			//printf("Pushing : top = %d\n" , top);
			/* Top points to the location -> last element */
		}
		else if ( array[i] == '}' ) {
			if ( top == -1 ) {
				top++;
				stack[top] = '{';
				ans ++;
				//printf("Error case Pushing : top = %d and ans = %d\n" , top, ans);
			}
			else if ( top != -1 ) {
				if( stack[top] == '{' ) {
					top--;
					//printf("Popping : top = %d\n" , top);
				}
				else {
					top++;
					stack[top] = '{';
					//printf("Pushing : top = %d and ans = %d\n" , top, ans);
				}
			}
		}
	}
	//printf("TOP = %d ans = %d\n" , top , ans);	
	if ( l == 0 )
		printf("%d. %d\n" , n , 0);
	else {
		if( top == -1  && ans == 0 )
			printf("%d. %d\n" , n , 0);
		else {
			//printf("TOP = %d ans = %d\n" , top , ans);
			printf("%d. %d\n" , n , ((top+1)/2) + ans);
		}
	}
}

int main( int argc , char * argv[] ) {
	char array[10000];
	int l = 0 , i = 0;;
	while ( 1 ) {

		l = readline(array);
		if( array[0] == '-' )
			break;
		i++;
		eval(i,array,l);

	}
	return 0;
}
