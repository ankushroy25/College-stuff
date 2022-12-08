#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;

void addend(Node **head, int val)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = val;
    ptr->next = NULL;

    if (*head == NULL)
    {
        *head=ptr;
        return;
    }
    Node *tail = *head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = ptr;   
}

int median(Node **head)
{
    Node *temp=*head;
    int len = 1,i,median=0;

    while (temp->next != NULL)
    {
        temp = temp->next;
        ++len;
    }

    temp=*head;

    if(len%2==0) //even 
    {
        for ( i = 1; i < (len/2); i++)
        {
            temp=temp->next;
        }
        median+=temp->data;
        temp=temp->next;
        median+=temp->data;
        median/=2;
    }
    else
    {
         for ( i = 1; i <= (len/2); i++)
        {
            temp=temp->next;
        }
        median=temp->data;
    }    

    return median;
}
int main()
{
    Node *head=NULL;
    char cont;
    int val,ch;
    do
    {
        printf("\nchoice :");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1: printf("enter value to insert :");
                scanf("%d",&val);
                addend(&head,val); 
            break;
        case 2: printf("Median : %d",median(&head));
            break;
        
        default:
            break;
        }
        
        printf("continue :");
        scanf("%s",&cont);

    } while (cont=='y');
    
    return 0;
}