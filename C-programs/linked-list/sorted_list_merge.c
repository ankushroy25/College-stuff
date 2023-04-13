//merge 2 given sorted lists and display them in sorted order
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
void createlist(Node **head, int val)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = val;
    ptr->next = NULL;
    *head = ptr;
}
void addend(Node **head, int val)
{
    if (*head == NULL)
    {
        createlist(head, val);
        return;
    }

    Node *ptr = (Node *)malloc(sizeof(Node));
    Node *last = *head;
    ptr->data = val;
    ptr->next = NULL;

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = ptr;
}
void printlist(Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
void linksort(Node **head1, Node **head2, Node **temp)
{
    Node *ptr1 = *head1;
    Node *ptr2 = *head2;

    if (ptr1->data <= ptr2->data)
    {
        *temp = ptr1;
        ptr1 = ptr1->next;
    }
    else
    {
        *temp = ptr2;
        ptr2 = ptr2->next;
    }
    Node* dummy=*temp;    
    
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data <= ptr2->data)
        {
           dummy->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            dummy->next = ptr2;
            ptr2 = ptr2->next;
        }
        dummy = dummy->next;
    }

    while (ptr1!= NULL)
    {
        dummy->next = ptr1;
        ptr1 = ptr1->next;
        dummy = dummy->next;
    }
    while (ptr2!= NULL)
    {
        dummy->next = ptr2;
        ptr2 = ptr2->next;
        dummy = dummy->next;
    }

    dummy->next = NULL;
}
int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *temp = NULL;

    addend(&head1, 1);
    addend(&head1, 5);
    addend(&head1, 9);

    addend(&head2, 2);
    addend(&head2, 3);
    addend(&head2, 6);
    addend(&head2, 10);

    printlist(head1);
    printlist(head2);
    linksort(&head1, &head2, &temp);
    printlist(temp);
    return 0;
}
