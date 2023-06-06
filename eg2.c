#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void main()
{
    char postfix[20], symbol;
    int top = -1, i;
    double stack[40], op1, op2, result;

    printf("\nEnter The PostFix Expression \n");
    scanf(" %s", postfix);

    for (i = 0; i < strlen(postfix); i++)
    {
        symbol = postfix[i];

        if (isdigit(symbol))
        {
            stack[++top] = symbol - '0';
        }
        else
        {
            op2 = stack[top--];
            op1 = stack[top--];

            switch (symbol)
            {
            case '+':
                result = op1 + op2;
                break;

            case '-':
                result = op1 - op2;
                break;

            case '/':
                result = op1 / op2;
                break;

            case '*':
                result = op1 * op2;
                break;

            case '$':
            case '^':
                result = pow(op1, op2);
                break;
            }
            stack[++top] = result;
        }
    }
    result = stack[top--];
    printf("Results = %f", result);
}
