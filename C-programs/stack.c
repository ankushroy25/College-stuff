// stack using array
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct stack
{
    int data, top;
    int arr[MAX];
} STACK;

int isFull(STACK *s)
{
    return (s->top == MAX - 1);
}
int isEmpty(STACK *s)
{
    return (s->top == -1);
}
void push(STACK *s, int val)
{
    if (isFull(s))
    {
        printf("Stack overflow\n");
    }
    else
    {
        s->arr[++s->top] = val;
    }
}
void pop(STACK *s)
{
    if (isEmpty(s))
        printf("Stack underflow\n");
    else
        printf("Popped element : %d\n", s->arr[s->top--]);
}
void peek(STACK *s)
{
    if (isEmpty(s))
        printf("Stack empty");
    else
        printf("Top element : %d\n",s->arr[s->top]);
}

void display(STACK *s)
{
    printf("Stack\n");
    for (int i = s->top; i >=0; i--)
    {
        printf("%d\n", s->arr[i]);
    }
}
int main()
{
    STACK s;
    s.top = -1;

    char cont;
    int ch, el;
    do
    {
        printf("\nEnter choice :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to push :");
            scanf("%d", &el);
            push(&s, el);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            peek(&s);
            break;
        case 4:
            display(&s);
            break;

        default:
            printf("Invalid input");
        }

        printf("Press 'y' to continue ");
        scanf("%s", &cont);
    } while (cont == 'y');
}