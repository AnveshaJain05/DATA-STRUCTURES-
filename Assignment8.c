#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isfull()
{
    if (rear == SIZE - 1)
        return 1;
    else
        return 0;
}

int isempty()
{
    if (rear == front)
        return 1;
    else
        return 0;
}

void AddQ(int element)
{
    if (isfull())
        printf("Queue is full\n");
    else
    {
        rear = rear + 1;
        queue[rear] = element;
        printf("Element inserted\n");
    }
}

void DelQ()
{
    int element;

    if (isempty())
        printf("Queue is empty\n");
    else
    {
        front = front + 1;
        element = queue[front];
        printf("Deleted element = %d\n", element);
    }
}

void display()
{
    int i;

    if (isempty())
        printf("Queue is empty\n");
    else
    {
        for (i = front + 1; i <= rear; i++)
            printf("%d ", queue[i]);

        printf("\n");
    }
}

int main()
{
    
    AddQ(10);
    AddQ(20);
    AddQ(30);

    display();

    DelQ();

    display();

    AddQ(40);
    AddQ(50);

    display();

    return 0;
}       