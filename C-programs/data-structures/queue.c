//queue using dynamic allocation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5
struct queue
{
    int front,rear,size;
    int* arr;
};
struct queue* createQueue()
{
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));    
    q->arr=(int*)malloc(MAX*sizeof(int));
    q->front=q->rear=-1;
    q->size=0;

    return q;
}
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
        q->arr[++q->rear]=item;
        if (q->front==-1)
            ++q->front;
    }    
}
void deq(struct queue* q)
{
     if (isEmpty(q))
        printf("Queue underflow");
    else
        ++q->front;
}

int main()
{
    struct queue* q=createQueue();

    int choice;
    
    printf("Enter choice :");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1: printf("Add element - ");
            int el;
            scanf("%d",&el);
            enq(q,el);        
        break;
    case 2: deq(q);
        break;
    case 3: for (int i = q->front; i <= q->rear; i++)
            {
                printf("%d  ",q->arr[i]);
            }
        break;
    
    default: printf("Invalid input");
    }

 return 0;
}