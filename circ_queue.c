#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5
struct queue
{
    int front,rear;
    int arr[MAX];
};

int isEmpty(struct queue* q)
{
    return(q->front==-1);
}
int isFull(struct queue* q)
{
    return(q->rear==MAX-1); 
}
void enq(struct queue* q,int item)
{
    if (isFull(q))
        printf("Queue overflow");
    else
    {
        q->rear=(q->rear+1)%MAX;
        q->arr[q->rear]=item;
        if (q->front==-1)
            ++q->front;
    }    
}
void deq(struct queue* q)
{
     if (isEmpty(q))
        printf("Queue underflow");
    else
        q->front=(q->front+1)%MAX;
}


int main()
{
    struct queue q;
    q.front=q.rear=-1; 

    // enq(q,5);
    // enq(q,15);
    // enq(q,25);
    // deq(q);
    // enq(q,35);
    int choice;
    
    printf("Enter choice :");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1: printf("Add element - ");
            int el;
            scanf("%d",&el);
            enq(&q,el);        
        break;
    case 2: deq(&q);
        break;
    case 3: for (int i = q.front; i <= q.rear; i++)
            {
                printf("%d  ",q.arr[i]);
            }
        break;
    
    default: printf("Invalid input");
    }

 return 0;
}