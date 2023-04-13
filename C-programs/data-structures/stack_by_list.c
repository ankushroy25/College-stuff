//Name -Ankush Roy
//CSE(C) - 2nd year
//Assignment - Stack using linked list

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}Node;

int isEmpty(Node* top)
{
    return(top==NULL);
}
void push(Node **top,int val)
{
    Node* ptr =(Node*)malloc(sizeof(Node));
    ptr->data = val;
    ptr->next = *top;
    *top = ptr;
}

void pop(Node** top)
{
    Node *temp;

    if(isEmpty(*top))
        printf("Underflow\n");
    else
    {
        printf("Popped element = %d\n", (*top)->data);

        temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}
void peek(Node **top)
{
    if (isEmpty(*top))
        printf("Stack Empty\n");
    else   
        printf("Top element = %d\n",(*top)->data);  
}
void printList(Node *top)
{
    Node *temp = top;
    if (isEmpty(top))
    {
        printf("Stack empty\n");
        return;
    }
    
    while(temp != NULL)
    {
         printf("%d\n", temp->data);
         temp = temp->next;
    }
    //printf("NULL\n");
}

int main()
{
    Node *top = NULL;


     printf("\tMENU \n1-Push \n2-Pop \n3-Peek \n4-Display stack \n");
    int ch, el, pos;
    char cont;

    do
    {
        printf("\nEnter your choice :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to push :");
            scanf("%d", &el);
            push(&top,el);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            peek(&top);
            break;
        case 4:
            printList(top);
            break;
        default: printf("Invalid choice");
            break;
        }

        printf("Press 'y' to continue ?");
        scanf("%s", &cont);

    } while (cont == 'y');

    return 0;
}