
#include <stdio.h>
#define size 20

int top = -1;
char stk[20];

int isfull()
{
    if (top == size - 1)
        return 1;
    else
        return 0;
}

int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void pushin(char c)
{
    if (isfull())
        printf("Stack Overflow\n");
    else
    {
        top++;
        stk[top] = c;
    }
}

char popin()
{
    char ch;

    if (isempty())
    {
        printf("Stack Underflow\n");
        return '\0';
    }

    ch = stk[top];
    top--;
    return ch;
}

int icp(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 4;
    if (ch == '(')
        return 5;
    return 0;
}

int isp(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 3;
    return 0;
}

void in_post(char inexp[])
{
    char postexp[100];
    char tkn;
    int k = 0, i = 0;

    top = -1;
    tkn = inexp[i];

    while (tkn != '\0')
    {
        if ((tkn >= 'A' && tkn <= 'Z') ||
            (tkn >= 'a' && tkn <= 'z') ||
            (tkn >= '0' && tkn <= '9'))
        {
            postexp[k] = tkn;
            k++;
        }
        else
        {
            if (tkn == '(')
            {
                pushin(tkn);
            }
            else
            {
                if (tkn == ')')
                {
                    while (top != -1 && stk[top] != '(')
                    {
                        postexp[k] = popin();
                        k++;
                    }

                    if (top != -1)
                        popin();
                }
                else
                {
                    while (top != -1 &&
                           isp(stk[top]) >= icp(tkn))
                    {
                        postexp[k] = popin();
                        k++;
                    }

                    pushin(tkn);
                }
            }
        }

        i++;
        tkn = inexp[i];
    }

    while (top != -1)
    {
        postexp[k] = popin();
        k++;
    }

    postexp[k] = '\0';

    printf("Postfix expression: %s\n", postexp);
}

int main()
{
    int choice;
    char c, inexp[100];

    printf("\n1. Push");
    printf("\n2. Pop");
    printf("\n3. Infix to postfix conversion");
    printf("\n4. Exit");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter character: ");
            scanf(" %c", &c);
            pushin(c);
            break;

        case 2:
            if (!isempty())
                printf("Popped element = %c\n", popin());
            else
                printf("Stack Underflow\n");
            break;

        case 3:
            printf("Enter infix expression: ");
            scanf("%99s", inexp);
            in_post(inexp);
            break;

        case 4:
            printf("Exiting\n");
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}
