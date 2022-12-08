//check equality of diff brackets in an expression
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    char bracket[1000];
    int top ;
};

int main()
{
    struct stack s;
    char str[1000];
    int i,f=0;

    printf("Input the string :");
    gets(str);
    s.top=-1;

    for ( i = 0; i < strlen(str); i++)
    {
        if ((str[i] == '(') || (str[i] == '{') || (str[i] == '['))
        {
            s.bracket[++s.top]=str[i]; //push
        }
        else if (str[i] == ')')
        {
            if (s.bracket[s.top] == '(') //pop
            {
                --s.top;
            }
            else
            {
                f++;
                break;
            } 
        }
        else if (str[i] == '}')
        {
            if (s.bracket[s.top] == '{')
            {
                --s.top;
            }
            else
            {
                f++;
                break;
            }
        }
        else if (str[i] == ']')
        {
            if (s.bracket[s.top] == '[')
            {
                --s.top;
            }
            else
            {
                f++;
                break;
            }
        }
    }
    printf("%d\n",s.top);
    if (f==0 && s.top==-1)
    {
        printf("Valid");
    }
    else
    {
        printf("mismatch");
    }
    return 0;
}