#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = 0, rear = 0;

int isfull()
{
    if ((rear + 1) % SIZE == front)
        return 1;
    else
        return 0;
}

int isempty()
{
    if (front == rear)
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
        rear = (rear + 1) % SIZE;
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
        front = (front + 1) % SIZE;
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
        i = (front + 1) % SIZE;

        while (1)
        {
            printf("%d ", queue[i]);

            if (i == rear)
                break;

            i = (i + 1) % SIZE;
        }

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