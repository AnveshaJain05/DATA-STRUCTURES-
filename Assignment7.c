
#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int x)
{
    top++;
    stack[top] = x;
}

int pop()
{
    int x;
    x = stack[top];
    top--;
    return x;
}

void evaluate(char postfix[])
{
    int i, a, b;
    char x;

    top = -1;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        x = postfix[i];

        if (isdigit(x))
        {
            push(x - '0');
        }
        else
        {
            b = pop();
            a = pop();

            switch (x)
            {
                case '+':
                    push(a + b);
                    break;

                case '-':
                    push(a - b);
                    break;

                case '*':
                    push(a * b);
                    break;

                case '/':
                    push(a / b);
                    break;
            }
        }
    }

    printf("result = %d\n", pop());
}

int main()
{
    char postfix[SIZE];

    printf("Enter postfix expression: ");
    scanf("%99s", postfix);

    evaluate(postfix);

    return 0;
}