/*
Magic set

Given a set of numbers if there is a number which is a prefix of some other number in the set then the set is not a magic set. 
eg. {123,234,12} here 12 is the prefix of 123 so it is not a magic set.
Input Specification:

The first line is the number of test cases, 1 <= t <= 100. 
Each test case starts with a number n, the number of numbers, on a separate line, 1 <= n <= 10000. Then follows n lines with one number on each line. Each number has atmost 12 digits. 
Output Specification:

For each test case, output “YES” if the set is a magic set or “NO” otherwise.
Sample Input:

 
2
3
123
234
12
3
123
234
34
Sample Output:

 
NO
YES
Timelimit: 1s
*/
#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct node {
	int val;
	struct node * child[10];
};

struct node * create_node ( int val ) {
        struct node * temp = new struct node;
        for ( int i = 0 ; i < 10 ; i++ ) {
                temp -> child[i] = NULL;
        }
        temp -> val = val;
        return temp;
}

void printlevelorder(struct node *root) {
	if (!root) return;

	queue<struct node*> currentLevel, nextLevel;
	currentLevel.push(root);

	while (!currentLevel.empty()) {
		struct node *currNode = currentLevel.front();
		currentLevel.pop();
		if (currNode) {
			cout << currNode->val << " ";
			for(int i = 0 ; i < 10; i++ ) {
      				nextLevel.push(currNode->child[i]);
			}
		}
		if (currentLevel.empty()) {
			cout << endl;
			swap(currentLevel, nextLevel);
		}
	}
}

int insert_trie ( struct node ** root , long int number ) {

	struct node * temp = *root;

	char number_str[13];

	sprintf(number_str , "%ld" , number);

	if ( (*root) == NULL ) {
		(*root) = create_node(-1);
		return -2;
	}

	int i = 0;

	int found = 1;

	while ( number_str[i] != '\0' ) {

		//cout <<"Character : " << number_str[i] << endl;

		int number = number_str[i] - '0';
		struct node * temp_node = create_node(number);

		//cout <<" Temp -> data = " << temp->val << endl;

		if ( temp == NULL ) {
			//cout << "a" << endl;
			temp = temp_node;
		}
		else if ( temp -> child[number] == NULL ) {
			//cout << "b" << endl;
			//cout << "Found " << number << " child of parent " << temp->val << " null" << endl;
			temp -> child[number] = temp_node;
			temp = temp -> child[number];
			found = 0;
		}
		else if ( temp -> val == number ) {
			//cout << "c" << endl;
			//cout << "Found " << number << " = that of parent " << temp->val << "" << endl;
			i++;
			temp = temp -> child[number];
			continue;
		}
		else {
			//cout << "d" << endl;
			i++;
			temp = temp -> child[number];
			continue;
		}

		i++;

	}

	return found;

}

int main ( int argc , char * argv[] ) {

	int t;

	cin >> t;	

	while ( t-- ) {

		//vector<long int> vec;
		vector<string> vec;

		int n;
		cin >> n;

		struct node * root;
		root = NULL;

		int flag = 0;
		insert_trie ( &root , -1 );

		for( int i = 0 ; i < n ; i++ ) {
			string number;
			cin >> number;
			vec.push_back(number);
		}

		sort ( vec.begin() , vec.end() );
		for ( int i = 0 ; i < n-1 ; i++ ) {
			if ( !vec[i+1].find(vec[i]) ) {
				flag = 1;
				break;
			}
		}

		/*for( int i = 0 ; i < n ; i++ ) {
			//cout << "Executing for number = " << number << endl;
			int already_present = insert_trie ( &root , vec[n-1-i] );
			//cout << "Root data : " << root->val << endl;
			if ( already_present == 1 ) {
				flag = 1;
				break;
			}
		}*/

		if ( flag == 1 ) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}

		//printlevelorder ( root );
	}
	return 0;
}
