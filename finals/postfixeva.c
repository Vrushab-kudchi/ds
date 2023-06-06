#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void main()
{
    int i, top = -1;
    char postfix[30], infix[30], symbol;
    double stack[40], op1, op2, result;
    printf("\nEnter the Postfix\n");
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
            op1 = stack[top--];
            op2 = stack[top--];

            switch (symbol)
            {
            case '+':
                result = op1 + op2;
                break;

            case '-':
                result = op1 - op2;
                break;

            case '*':
                result = op1 * op2;
                break;

            case '/':
                result = op1 / op2;
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
    printf("Results = %f \n", result);
}
