/*
A user is typing a sentence using his keyboard. He uses only the keys, 'a' - 'z', H (home) and E(end). Given the sequence of key presses, find the line that is printed on the screen finally. Initially, a cursor is placed at the beginning of empty line and the following actions are performed with each key stroke.

- when 'a'-'z' is pressed, its printed at current cursor position after moving the rest of the string to right. For eg. If the current cursor position is at t in the string "deter", pressing a 'x' key results in the string "dexter".

- when 'H' is pressed, cursor moves to the beginning. For eg: pressing 'H' when we have "apple" results in string "apple"

- when 'E' is pressed, cursor moves to the end of the string. For eg: pressing 'E' when we have "apple" results in string "apple "

Its just like any normal editors we use. Try it out pressing 'a' - 'z', Home and End keys to get a feel of it :)

Input:
Only one line, contains a long string of at most 100000 valid characters

Output:
Print the final string in a single line, followed by a '\n' ( just print a new line, no need to display '\n' )

Constraints:
Time Limit : 1s
Sample Case 1:

Input:
atHc

Output:
cat\n

Explanation:
" " → "a " → "at " → "at" → "cat"


Sample Case 2:

Input:
rHsEocHpEkHaEs

Output:
apsrocks\n

Explanation:
Of course, whats there to explain... just experience it ! 
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	char val;
	struct node *next;
	struct node *prev;
}node;
typedef struct dll
{
	struct node *head,*tail;
}dll;


void init(dll *l)
{
	(l->head)=NULL;
}


int main () {

	char ch = 0;
	node *head = NULL , *current = NULL , *end = NULL;
	int flag_h = 0 ;
	int len = 0;

	while ( (ch = getchar()) != '\n' ) {

		if ( ch == 'H' ) {
			current = head;
			flag_h = 1;
			continue;
		}
		if ( ch == 'E' ) {
			current = end;
			flag_h = 0;
			continue;
		}

		node * temp = (node *) malloc ( sizeof(node) );
		temp -> next = NULL;
		temp -> val = ch;

		if ( head == NULL ) {
			head = temp;
			end = temp;
			current = temp;
			len ++;
			flag_h = 0;
			continue;
		}

		if ( flag_h == 1 ) {
			temp -> next = head;
			head = temp;
			current = head;
			//printf("For char %c : flag = %d\n" , temp->val , flag_h);
			flag_h = 0;
		}
		else {
			if ( current -> next == NULL )
				end = temp;
			temp -> next = current -> next;
			current -> next = temp;
			current = temp;

		}
		len ++;

	}

	node * p = head;
	while( len -- )
	{
		printf("%c",p->val);
		p=p->next;
	}
	printf("\n");

	
	return 0;
}
