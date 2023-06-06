#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define STACK_SIZE 20

int main() {
    double stack[STACK_SIZE];
    double result, op1, op2;
    int top = -1, i;
    char postfix[20], symbol;

    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    for(i = 0; i < strlen(postfix); i++) {
        symbol = postfix[i];
        if(isdigit(symbol)) {
            top++;
            stack[top] = symbol - '0';
        } else {
            op2 = stack[top--];
            op1 = stack[top--];
            switch(symbol) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^':
                case '$': result = pow(op1, op2); break;
            }
            top++;
            stack[top] = result;
        }
    }

    result = stack[top--];
    printf("The result is = %f\n", result);

    return 0;
}
