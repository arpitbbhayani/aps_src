#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define LEFT 0
#define RIGHT 1

using namespace std;

struct node {
	int val;
	struct node * child[2];
};

struct node * create_node ( int val ) {
	struct node * temp = new struct node;
	temp -> val = val;
	temp -> child[LEFT] = NULL;
	temp -> child[RIGHT] = NULL;

	return temp;
}

int index_preorder = 0;

int least_common_ancestor( vector<int> , vector<int> , int , int );

struct node * construct_tree ( vector<int> inorder , vector<int> preorder , int start , int end ) {

	if ( start > end ) {
		return NULL;
	}

	struct node * t = create_node ( preorder[index_preorder++] );

	if ( start == end ) {
		return t;
	}

	int search_index = distance ( inorder.begin() , find ( inorder.begin() , inorder.end() , t->val ));

	t -> child[LEFT] = construct_tree ( inorder , preorder , start , search_index - 1 );
	t -> child[RIGHT] = construct_tree ( inorder , preorder , search_index + 1 , end );

	return t;
}

int least_common_ancestor_r ( struct node * root , int a , int b ) {

	if ( root == NULL ) {
		return INT_MIN;
	}

	if ( root->val == a || root-> val == b ) {
		return root->val;
	}

	int left = least_common_ancestor_r ( root->child[LEFT] , a , b );
	int right = least_common_ancestor_r ( root->child[RIGHT] , a , b );

	if ( left != INT_MIN && right != INT_MIN ) {
		return root->val;
	}
	else {
		if ( left != INT_MIN )
			return left;
		else
			return right;
	}

	return 0;
}

int least_common_ancestor ( vector<int> preorder , vector<int> inorder , int a , int b ) {

	int count = 0;

	int index_a = 0 , index_b = 0;

	for ( unsigned int i = 0 ; i < inorder.size() ; i++ ) {
		if ( inorder[i] == a ) {
			index_a = i;
			count ++;
		}
		if ( inorder[i] == b ) {
			index_b = i;
			count ++;
		}
		if ( count == 2 )
			break;
	}

	if ( index_a > index_b ) {
		int t = index_a;
		index_a = index_b;
		index_b = t;
	}

	for( unsigned int i = 0 ; i < preorder.size() ; i++ ) {
		for ( int j = index_a ; j <= index_b ; j++ ) {
			if ( preorder[i] == inorder[j] ) {
				return inorder[j];
			}
		}
	}

	return preorder[0];
} 

int main( int argc , char * argv[] ) {

	int n , a ;
	vector<int> preorder, inorder;

	cin >> n;

	for ( int i = 0 ; i < n ; i++ ) {
		cin >> a;
		preorder.push_back( a );
	}

	for ( int i = 0 ; i < n ; i++ ) {
		cin >> a;
		inorder.push_back( a );
	}


	/*struct node * root = construct_tree ( inorder , preorder , 0 , n - 1 );

	cin >> n;

	for ( int i = 0 ; i < n ; i++ ) {
		int a , b;
		cin >> a >> b;

		cout << least_common_ancestor_r( root , a , b ) << endl;

	}*/

	cin >> n;
	for ( int i = 0 ; i < n ; i++ ) {
		int a , b;
		cin >> a >> b;
		cout << least_common_ancestor ( preorder , inorder , a , b ) << endl;
	}

	return 0;
}
