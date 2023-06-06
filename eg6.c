#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STACK_SIZE 50

char stack[STACK_SIZE];
int top = -1;

char isOperand(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

char isOperator(char c)
{
    return(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '$');
}


int precedence(char c)
{
    if(c == '+' || c == '-')
        return 1;
    if(c == '*' || c == '/')
        return 2;
    if(c == '^' || c == '$')
        return 3;
    return 0;
}

int push(char c)
{
    if(top == STACK_SIZE -1)
    {
        printf("\nStack is full");
        exit(0);
    }
    stack[++top] = c;
}

int pop()
{
    if(top == -1)
    {
        printf("\nStack is empty");
        exit(0);
    }
    return stack[top--];
}

void infix_postfix(char infix[] ,char postfix[])
{
    int i , j= 0;
    char c;
    for (i = 0; i < strlen(infix) ;i++)
    {
        c = infix[i];
        if (isOperand(c))
        {
            postfix[j++] = c;
        }else if(isOperator(c))
        {
            while(precedence(stack[top]) >= precedence(c))
            {
                postfix[j++] = pop();
            }
            push(c);
        }else if(c == '(')
        {
            push(c);
        }else if(c == ')')
        {
            while(stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
    }
    while(top != -1 )
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

void main()
{
    char postfix[50], infix[50];
    printf("Enter The Infix Expression :\n");
    scanf("%s" ,infix);
    infix_postfix(infix,postfix);
    printf("postfix Expression : %s" ,postfix);
}
