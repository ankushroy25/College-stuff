#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void input(int **a)
{
    for (int i = 0; i < SIZE; i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    
}
void sparse(int **sp,int **a)
{
    int k=0;
    for (int i = 0; i < SIZE; i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            if (a[i][j]!=0)
            {
                sp[k][0]=i;
                sp[k][1]=j;
                sp[k][2]=a[i][j];
                k++;
            }           
        }
    }
}
// void print(int **sp,int count)
// {
//     for (int i = 0; i < count; i++)
//     {
//         for (int  j = 0; j < 3; j++)
//         {
//             print("%d ",sp[i][j]);
//         }
//         printf("\n");
//     }
    
// }
int main()
{
    int count=0;
     int* a[3];
    for (int i = 0; i < 3; i++)
        a[i] = (int*)malloc(3 * sizeof(int));
    
    input(a);


    for (int i = 0; i < SIZE; i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            if(a[i][j]!=0)
            count++;
        }
    }

    int* arr[3];
    for (int i = 0; i < 3; i++)
        arr[i] = (int*)malloc(3 * sizeof(int));
    
    sparse(arr,a);
    //print(arr,count);


    return 0;
}