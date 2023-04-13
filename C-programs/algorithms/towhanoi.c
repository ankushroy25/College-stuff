#include <stdio.h>
int tower(int n, char src, char temp, char des, int c)
{
    if (n >= 1)
    {
        c = tower(n - 1, src, des, temp, c);                 // moving the upper set to temp rod using the temp as dest for that set
        printf("Move disk %d from %c to %c\n", n, src, des); // moving the single disk from src to dest
        ++c;
        c = tower(n - 1, temp, src, des, c); // movin that upper set from temp to dest using the src as temp rod
    }
    return c;
}
int main()
{
    int n, moves;
    printf("Enter the number of towers : ");
    scanf("%d", &n);
    moves = tower(n, 'A', 'B', 'C', 0);
    printf("No. of moves : %d\n", moves);
    return 0;
}