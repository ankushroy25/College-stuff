#include <stdio.h>
void tower(int n, char src,char temp,char des)
{
    if(n==1)
        printf("Move disk %d from %c to %c\n",n,src,des);
    else
    {
        tower(n-1,src,des,temp);//moving the upper set to temp rod using the temp as dest for that set
        printf("Move disk %d from %c to %c\n",n,src,des);//moving the single disk from src to dest
        tower(n-1,temp,src,des);//movin that upper set from temp to dest using the src as temp rod
    }
}
int main()
{
    tower(4,'A','B','C');
    return 0;
}