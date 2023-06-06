// infix to Postfix

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STACK_SIZE 20

int stack[STACK_SIZE], top = -1;

char isOperand(char c)
{
    return((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

char isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void push(char c)
{
    if(top == STACK_SIZE-1)
    {
        printf("Array is Full\n");
    }
    stack[++top] = c;
}

int pop()
{
    if(top == -1)
    {
        printf("\n Queue is Empty");
    }
    return stack[top--];
}

char precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^' || c == '$')
        return 3;
    return 0;
}

void infix_postfix(char postfix[] , char infix[])
{
    int i,j=0;
    char c;
    for (i = 0; i < strlen(infix); i++)
    {
        c = infix[i];
        if(isOperand(c))
        {
            postfix[j++] = c;
        }else if(isOperator(c))
        {
            while(precedence(stack[top])>= precedence(c))
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
    while(top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] == '\0';
}


void main()
{
    char postfix[50], infix[50];
    printf("Enter the infix expression : ");
    scanf("%s" ,infix);
    infix_postfix(postfix, infix);
    printf("Result = %s" ,postfix);
}
