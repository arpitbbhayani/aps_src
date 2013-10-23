#include <iostream>
#include <vector>
#include <algorithm>

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

void preorder_r ( struct node * root ) {
	if ( root == NULL )
		return;
	cout << root->val << " ";
	preorder_r ( root->child[LEFT] );
	preorder_r ( root->child[RIGHT] );
}

void inorder_r ( struct node * root ) {
	if ( root == NULL )
		return;
	inorder_r ( root->child[LEFT] );
	cout << root->val << " ";
	inorder_r ( root->child[RIGHT] );
}

int diameter_r ( struct node * root , int * height ) {

	int left_height = 0 , right_height = 0;
	int left_diameter = 0 , right_diameter = 0;

	if ( root == NULL ) {
		*height = 0;
		return 0;
	}

	left_diameter = diameter_r ( root-> child[LEFT] , &left_height );
	right_diameter = diameter_r ( root-> child[RIGHT] , &right_height );

	*height = max ( left_height , right_height ) + 1;

	return max( left_height + right_height + 1 , max ( left_diameter , right_diameter ) ) ;
}

int main( int argc , char * argv[] ) {

	int n , a , height;
	vector<int> preorder, inorder;

	cin >> n;

	for ( int i = 0 ; i < n ; i++ ) {
		cin >> a;
		preorder.push_back( a );
		inorder.push_back( a );
	}

	sort( inorder.begin() , inorder.end() );

	struct node * root = construct_tree ( inorder , preorder , 0 , n - 1 );

	cout << diameter_r( root , &height ) - 1 << endl;

	return 0;
}
