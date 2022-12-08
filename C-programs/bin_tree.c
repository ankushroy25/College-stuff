#include <stdio.h>
#include <stdlib.h>
typedef struct  node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *createnode(int val)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL; 

    return newnode;
}
void preorder(Node *root)
{
    if(root==NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    int i, j, k, l, m, n;
 
    Node *root=createnode(2);
 
    Node *l1=createnode(1);
    root->left=l1;
    Node *r1=createnode(6);
    root->right=r1;
    
    Node *l2=createnode(3);
    l1->left=l2;
    Node *r2=createnode(10);    
    r1->left=r2;
    
    /* tree looks like this
                2
            1       6
        3               10
    */

   preorder(root);
    return 0;
}