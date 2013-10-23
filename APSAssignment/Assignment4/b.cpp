#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define LEFT 0
#define RIGHT 1

using namespace std;

struct node {
	int val;
	struct node * child[2];
};

struct node * create_node ( int val ) {
	struct node * t = new struct node;
	t -> val = val;
	t -> child[LEFT] = NULL;
	t -> child[RIGHT] = NULL;
	return t;
}

void level_order ( struct node * root ) {

	struct node * t;
	queue<struct node *> q;

	q.push(root);

	while ( !q.empty() ) {

		t = q.front();
		q.pop();

		cout << t->val << " ";

		if ( t -> child[LEFT] != NULL ) {
			q.push( t -> child[LEFT] );
		}
		if ( t -> child[RIGHT] != NULL ) {
			q.push( t -> child[RIGHT] );
		}

	}

	cout << endl;
	
}

void inorder ( struct node * root ) {

	struct node * temp;
	stack<struct node *> s;

	s.push(root);

	temp = root;

	while ( !s.empty() ) {

		while ( temp -> child[LEFT] != NULL ) {
			s.push( temp -> child[LEFT] );
			temp = temp -> child[LEFT];
		}
	
		temp = s.top();
		s.pop();

		cout << temp -> val << " ";

		if ( temp -> child[RIGHT] != NULL ) {
			s.push ( temp -> child[RIGHT] );
			temp = temp -> child[RIGHT];
		}

	}

	cout << endl;
}

void postorder ( struct node * root ) {

	struct node * temp;

	stack<struct node *> s;

	temp = root;

	do {
		while ( temp != NULL ) {
			if ( temp -> child[RIGHT] != NULL ) {
				s.push( temp -> child[RIGHT] );
			}
			s.push ( temp );
			temp = temp -> child[LEFT];
		}

		temp = s.top();
		s.pop();

		if ( temp -> child[RIGHT] != NULL && !s.empty() && s.top() == temp -> child[RIGHT] ) {
			s.pop();
			s.push ( temp );
			temp = temp -> child[RIGHT];
		}
		else {
			cout << temp->val << " ";
			temp = NULL;
		}

	} while ( !s.empty() );

	cout << endl;

}

void insert_tree ( struct node ** root , int val ) {
	struct node * temp;

	if ( (*root) == NULL ) {
		(*root) = create_node( val );
		return ;
	}

	temp = (*root);

	while ( 1 ) {

		struct node * child;

		if ( val < temp->val ) {
			child = temp -> child[LEFT];
			if ( child == NULL ) {
				temp -> child[LEFT] = create_node( val );
				break;
			}
			else {
				temp = temp -> child[LEFT];
			}
		}
		else {
			child = temp -> child[RIGHT];
			if ( child == NULL ) {
				temp -> child[RIGHT] = create_node( val );
				break;
			}
			else {
				temp = temp -> child[RIGHT];
			}
		}
	}

}

int main ( int argc , char * argv[] ) {

	int n , a;
	struct node * root = NULL;

	cin >> n;

	vector<int> numbers;

	for ( int i = 0 ; i < n ; i++ ) {
		cin >> a;
		insert_tree( &root , a );
	}

	inorder ( root );
	postorder ( root );
	level_order ( root );
	
	return 0;
}
