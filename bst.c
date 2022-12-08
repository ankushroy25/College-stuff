#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct  node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

Node* createnode(int val)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode; 
}
Node* insert(Node *root,int val)
{
    if(root==NULL)
        return(createnode(val));

    if(val<root->data)
        root->left=insert(root->left,val);
    else
        root->right=insert(root->right,val);

    return(root);
}

void inorder(Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }    
    printf("\n");
}
int main()
{
    Node* root=NULL;
    int val,ch;
    char cont;

    printf("MENU \n1-Attach new node \n2-Display tree \n");
    do
    {
        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1 :
            printf("Enter node value: ");
            scanf("%d",&val);
            root=insert(root,val);
            break;
        case 2 : inorder(root);
            break;
        default:
            break;
        }
        printf("Press y to continue :");
        scanf("%s",&cont);

    } while (cont=='y');
     

    return 0;
}