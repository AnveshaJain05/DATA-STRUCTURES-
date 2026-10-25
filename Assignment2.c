#include <stdio.h>

void acc(int a[10][10], int r, int c)
{
    int i, j;

    printf("Enter matrix elements:\n");

    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
}

void display(int a[10][10], int r, int c)
{
    int i, j;

    printf("Original matrix:\n");

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            printf("%d\t", a[i][j]);

        printf("\n");
    }
}

void disp(int s[100][3], int r, int c)
{
    int i, j;

    printf("Compact matrix:\n");

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            printf("%d\t", s[i][j]);

        printf("\n");
    }
}

void sparse(int a[10][10], int r, int c)
{
    int s[100][3], i, j, k = 1;

    s[0][0] = r;
    s[0][1] = c;
    s[0][2] = 0;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(a[i][j] != 0)
            {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = a[i][j];
                k++;
            }
        }
    }

    s[0][2] = k - 1;

    disp(s, k, 3);
}

int main()
{
    int a[10][10], r, c;

    printf("Enter rows and columns: ");
    scanf("%d%d", &r, &c);

    acc(a, r, c);
    display(a, r, c);
    sparse(a, r, c);

    return 0;
}