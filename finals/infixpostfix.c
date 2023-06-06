#include <stdio.h>
#include <string.h>

#define StackSize 30

char stack[StackSize];
int top = -1;

int operator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '$' || c == '^');
}

char operand(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
    
}

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '$' || c == '^')
        return 3;
    return 0;
}

char push(char c)
{
    if (top == StackSize - 1)
    {
        printf("Stack is full \n");
        return 0;
    }
    stack[++top] = c;
}

char pop()
{
    if (top == -1)
    {
        printf("\n Stack is empty");
        return 0;
    }
    return stack[top--];
}

void infix_postfix(char infix[], char postfix[])
{
    char c;
    int i, j = 0;
    for (i = 0; i <= strlen(infix); i++)
    {
        c = infix[i];
        if (operand(c))
        {
            postfix[j++] = c;
        }
        else if (operator(c))
        {
            while (precedence(stack[top] > precedence(c)))
            {
                postfix[j++] = pop();
            }
            push(c);
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
    }
    while (top != -1)
    {
        postfix[j++] = pop();
    }
}

void main()
{
    char postfix[30], infix[30];
    printf("\nEnter infix \n");
    scanf("%s", infix);
    infix_postfix(infix, postfix);
    printf("\n Results : %s", postfix);
}
