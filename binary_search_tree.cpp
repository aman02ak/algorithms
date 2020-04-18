#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	node *left;
	node *right;
}node;

node* newNode(int x)
{
	node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

node* insert(node *root, int x)
{
	if(root==NULL)
		return newNode(x);
	
	if(x<root->data)
		root->left = insert(root->left,x);
	else if(x>root->data)
		root->right = insert(root->right,x);
	return root;
}

void inorder(node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout << root->data << ' ';
		inorder(root->right);
	}
}

int main()
{
	node *root = NULL;
	root = insert(root,50);
	insert(root,30);
	insert(root,20);
	insert(root,40);
	insert(root,70);
	insert(root,60);
	insert(root,80);
	
	inorder(root);
	cout << endl;
	return 0;
}
