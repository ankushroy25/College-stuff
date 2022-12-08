#include <stdio.h>
// #include <math.h>
#include <stdlib.h>
#define MAX 10
void input(int *a)
{
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
}
int search(int *a, int el)
{
    int low = 0, high =  MAX, mid;
    while(low<=high)
    {
        mid=(low+high)/2; // mid= low+ (high -low)/2;
        if(el==a[mid])
        {
            return mid;
        }
        else if (el<a[mid])
        {
            high=mid-1;
        }
        else if(el>a[mid])
        {
            low=mid+1;
        }
    }
    return -1;
}
int main()
{
    int n, s;
    int *arr = (int *)malloc(10 * sizeof(int));

    printf("Enter array elements:");
    input(arr);

    printf("Enter number to search :");
    scanf("%d", &s);

    if(search(arr, s)>=0)
        printf("Input found at %dth position",search(arr,s)+1);
    else
        printf("Not found");

    return 0;
}