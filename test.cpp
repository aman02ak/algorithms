#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    node *left, *right;
}node;

node* newNode(int x);
node* insert(node* root, int x);
void printlist(node* root)
{
    if(root!=NULL)
    {
        printlist(root->left);
        cout << root->data << ' ';
        printlist(root->right);
    }
}

node* findMin(node* root)
{
    if(root == NULL)
        cout << "The tree is empty." << endl;
    else
    {
        node* temp = root;
        while(temp->left != NULL)
            temp = temp->left;
        return temp;
    }
}

node* deleteNode(node* root, int x)
{
    if(root == NULL)
        return root;
    else if(x < root->data)
        root->left = deleteNode(root->left, x);
    else if(x > root->data)
        root->right = deleteNode(root->right, x);
    else //root node have to delete and update
    {
        if(root->left == NULL && root->right == NULL) //node having no child
        {
            delete root;
            root = NULL;
        }
        else if(root->left==NULL || root->right==NULL) //node having one child
        {
            if(root->left == NULL)
            {
                node* temp = root;
                root = root->right;
                cout << "Item Deleted : " << temp->data << endl;
                delete temp;
            }
            else if(root->right == NULL)
            {
                node* temp = root;
                root = root->left;
                cout << "Item Deleted : " << temp->data << endl;
                delete temp;
            }
        }
        else //node having two child
        {
            node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main()
{
    node *root = NULL;
    // 50 30 20 40 70 60 80
    root = insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);


    printlist(root);
    cout << endl;

    root = deleteNode(root, 70);
    printlist(root);
    cout << endl;
    return 0;
}

node* newNode(int x)
{
    node *p = (node*)malloc(sizeof(node));
    p->data = x;
    p->left = p->right = NULL;
    return p;
}

node* insert(node* root, int x)
{
    if(root==NULL)
        return newNode(x);
    node* t = root;
    if(x > t->data)
        t->right = insert(t->right, x);
    else
        t->left = insert(t->left, x);
    return t;
}