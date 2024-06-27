#include <stdio.h>
#define SIZE 6

int queue[SIZE];
int front = -1, rear = -1;

int checkFull()
{

    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
    {
        return 1;
    }

    return 0;
}

int checkEmpty()
{
    if (front == -1)
    {
        return 1;
    }
    return 0;
}

void enqueue(int value)
{
    // rear + 1에서 삽입이 일어남.
    if (checkFull())
        printf("Overflow condition\n");
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
    }
    return;
}

int dequeue()
{
    // front에서 삭제가 일어남.
    if (checkEmpty())
    {
        printf("Underflow condition\n");
        return -1;
    }
    else
    {
        int rt = queue[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
        return rt;
    }
}

void display()
{
    int i;
    if (checkEmpty())
        printf("Nothing to dequeue\n");

    else
    {
        for (i = front; i != rear; i = (i + 1) % SIZE)
        {
            printf("%d \n", queue[i]);
        }
        printf("%d \n\n", queue[i]);
    }
}

int main()

{

    enqueue(15);
    enqueue(20);
    display();

    dequeue();
    display();

    dequeue();
    dequeue(); // Underflow condition

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7); // Overflow condition
    display();

    return 0;
}