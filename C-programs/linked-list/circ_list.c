#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void createlist(struct node **head, int val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    *head = ptr;
    ptr->next = *head;  
}
void delbeg(struct node **head)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr = *head;
    *head = ptr->next;
    free(ptr);
}
void delpos(struct node **head, int pos)
{
    struct node *temp1, *temp2;
    temp1 = *head;

    for (int i = 1; i < pos; i++)
    {
        if (temp1->next == NULL)
        {
            printf("Out of size");
            return;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = temp1->next;
    free(temp1);
}
void delend(struct node **head)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *last = *head;
    if (*head != NULL)
    {
        while (last->next->next != NULL)
        {
            last = last->next;
        }
        ptr = last->next;
        last->next = NULL;
        free(ptr);
    }
}
void addbeg(struct node **head, int val)
{
    if (*head == NULL)
    {
        createlist(head, val);
        return;
    }
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = *head;
    *head = ptr;
}
void addpos(struct node **head, int val, int pos)
{
    struct node *temp = *head;

    if (*head == NULL && pos > 1)
    {
        printf("List exceeded");
        // createlist(&head,val);
        return;
    }
    for (int i = 1; i < pos - 1; i++)
    {
        if (temp->next == NULL)
        {
            printf("Overlinked");
            return;
        }
        temp = temp->next;
    }

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = temp->next;
    temp->next = ptr;
}
void addend(struct node **head, int val)
{
    if (*head == NULL)
    {
        createlist(head, val);
        return;
    }

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *last = *head;
    ptr->data = val;
    ptr->next = NULL;

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = ptr;
}
void reverse(struct node **head)
{
    struct node *prev, *temp, *next;
    prev = NULL;
    temp = *head;
    next = NULL;
    while (temp != NULL)
    {
        next = temp->next;
        temp->next = prev;

        prev = temp;
        temp = next;
    }
    *head = prev;
}
void printlist(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct node *head = NULL;

    printf("\tMENU \n1-Add beginning \n2-Add last \n3-Add at a position \n4-Delete beginning \n5-Delete last \n6-Delete from a position \n7-Reverse \n8-Print List \n");
    int ch, el, pos;
    char cont;

    do
    {
        printf("\nEnter your choice :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to add :");
            scanf("%d", &el);
            addbeg(&head, el);
            break;
        case 2:
            printf("Enter the element to add :");
            scanf("%d", &el);
            addend(&head, el);
            break;
        case 3:
            printf("Enter the element to add :");
            scanf("%d", &el);
            printf("Enter the position :");
            scanf("%d", &pos);
            addpos(&head, el, pos);
            break;
        case 4:
            delbeg(&head);
            break;
        case 5:
            delend(&head);
            break;
        case 6:
            printf("Enter the position to delete :");
            scanf("%d", &pos);
            delpos(&head, pos);
            break;
        case 7:
            printf("List is Reversed \n");
            reverse(&head);
            break;
        case 8:
            printlist(head);
            break;
        default: printf("Invalid choice");
            break;
        }

        printf("Press 'y' to continue ?");
        scanf("%s", &cont);

    } while (cont == 'y');

    return 0;
}