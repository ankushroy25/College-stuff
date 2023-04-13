#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *createnode(int val)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}
Node *insert(Node *root, int val)
{
    if (root == NULL)
        return (createnode(val));

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return (root);
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void search(Node *root, int s)
{
    if (root == NULL)
    {
        printf("NOT FOUND \n");
        return;
    }

    if (root->data == s)
    {
        printf("FOUND \n");
        return;
    }
    if (s < root->data)
        return search(root->left, s);
    else
        return search(root->right, s);
}

void delete_node(Node *root, int x)
{
    // Find the node to be deleted
    Node *p = root;
    Node *parent = NULL;
    while (p != NULL && p->data != x)
    {
        parent = p;
        if (x < p->data)
            p = p->left;
        else
            p = p->right;
    }

    if (p == NULL)
        return; // x not found

    // Case 1: p has no children
    if (p->left == NULL && p->right == NULL)
    {
        if (parent == NULL)
            root = NULL; // p is the root node
        else
        {
            if (parent->left == p)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
    }

    // Case 2: p has one child
    else if (p->left == NULL || p->right == NULL)
    {
        Node *child = (p->left != NULL) ? p->left : p->right;
        if (parent == NULL)
            root = child; // p is the root node
        else
        {
            if (parent->left == p)
                parent->left = child;
            else
                parent->right = child;
        }
    }

    // Case 3: p has two children
    else
    {
        Node *successor = p->right;
        while (successor->left != NULL)
            successor = successor->left;

        // Replace p->data with successor->data
        p->data = successor->data;

        // Delete the successor, which has at most one child
        if (successor->right == NULL)
            p->right = NULL;
        else
            p->right = successor->right;
    }
}
int main()
{
    Node *root = NULL;
    int val, ch;
    char cont;

    printf("MENU \n1-Attach new node \n2-Display tree \n3-Search \n4-Delete \n");
    do
    {
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter node value: ");
            scanf("%d", &val);
            root = insert(root, val);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            printf("Enter value to search :");
            scanf("%d", &val);
            search(root, val);
            break;
        case 4:
            printf("Enter value to delete :");
            scanf("%d", &val);
            delete_node(root, val);
            break;

        default:
            break;
        }
        printf("Press y to continue :");
        scanf("%s", &cont);

    } while (cont == 'y');

    return 0;
}