#include <stdio.h>
#include <stdlib.h>
void swap(int*a,int i,int j)
{
    int temp;
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
int partition(int*a,int start,int end)
{
    int i,j,pivot,temp; 
    pivot=a[end];
    i=start;// i will be the pivot index

    for(j=start;j<end;j++)
    {
        if(a[j]<pivot)
        {
            swap(a,i,j);
            i++;
        }
    }
    swap(a,i,end);

    return i;
}
void quicksort(int *a, int start, int end)
{
    if (start>end)
        return ;
    
    int pividx=partition(a, start, end);

    quicksort(a,start,pividx-1);
    quicksort(a,pividx+1,end);        
}
int main()
{
    int i,n;

    printf("Enter array size");
    scanf("%d",&n);

    int *arr=(int*)malloc(n*sizeof(int));

    printf("Enter array elements :-\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("Array after sorting :-\n");
    quicksort(arr,0,n-1);
    
    for ( i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }

}