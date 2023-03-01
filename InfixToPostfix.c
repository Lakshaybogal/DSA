#include<stdio.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}
int CheckAlp(char exp)
{
    if( (exp>='A' && exp<='Z' )|| (exp>='a' && exp<='z' ))
    {
        return 1;
    }
    return 0;
}
int main()
{
    char exp[100];
    char x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    int i =0;
    while(exp[i] != '\0')
    {
        if(CheckAlp(exp[i]))
            printf("%c ",exp[i]);
        else if(exp[i] == '(')
            push(exp[i]);
        else if(exp[i] == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(exp[i]))
                printf("%c ",pop());
            push(exp[i]);
        }
        i++;
    }
    while(top != -1)
    {
        printf("%c ",pop());
    }return 0;
}
