/*
PostOrder from Preorder
Given a Preorder traversal of a Binary Search Tree of size N, Print the Kth element in Postorder of the same.
You will be given Q queries of input K and you have to print Kth element in Postorder of the BST.

Input:
First Line contains N, number of nodes in a tree (1<=N<=300000).
Second line will have N INTEGERS separated by space which represents Preorder traversal of the BST.
Third Line contains Q, number of queries(1<=Q<=10).
Fourth line would have Q integers separated by space representing K(1<=K<=N).

Output:
Q lines each with printed Kth element in Postorder traversal Of BST.

Sample test case:
Input:
7
5 3 2 4 8 7 9
3
1 3 5
Output:
2
3
9

Explaination:
Postorder traversal for the the BST would be 2 4 3 7 9 8 5.
So for K=1 => ans=2 , K=3 => ans=3, K=5 => ans=9.
*/

#include<stdlib.h>
#include<stdio.h>

struct tree_el {
   int val;
   struct tree_el * right, * left;
};

typedef struct tree_el node;

void insert(node ** tree, node * item) {
   if(!(*tree)) {
      *tree = item;
      return;
   }
   if(item->val<(*tree)->val)
      insert(&(*tree)->left, item);
   else if(item->val>(*tree)->val)
      insert(&(*tree)->right, item);
}
int k = 0;
void printout(node * tree , int * array) {
   if(tree->left) printout(tree->left , array);
   if(tree->right) printout(tree->right , array);
   array[k++] = tree->val;
}

int main() {
   node * curr, * root;
   int i;
   int n;

	scanf("%d" , &n);

   root = NULL;

	int a;
   for(i=1;i<=n;i++) {
	scanf("%d" , &a);
      curr = (node *)malloc(sizeof(node));
      curr->left = curr->right = NULL;
      curr->val = a;
      insert(&root, curr);
   }
	int * array = (int *) malloc ( n * sizeof(int) );
   printout(root , array);
	scanf("%d" , &n);

	for ( i = 0 ; i < n ; i++ ) {
		scanf("%d" , &a);
		printf("%d\n" , array[a-1]);
	}
	return 0;
}
