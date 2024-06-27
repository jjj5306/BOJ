#include <stdio.h>
#define SIZE 100

void enqueue(int n);
int dequeue();
void show();

int inp_arr[SIZE];
int Rear = -1;
int Front = -1;

int main()
{

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    show();

    dequeue();
    dequeue();

    show();
}

void enqueue(int n)
{
    // Front + 1에서 삽입이 일어남.
    if (++Front >= SIZE)
    {
        printf("Queue is full.\n");
        return;
    }

    inp_arr[Front] = n;
}

int dequeue()
{
    // Rear + 1에서 삭제가 일어남.
    if (++Rear > Front)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return inp_arr[Rear];
}

void show()
{
    for (int i = Rear + 1; i <= Front; i++)
        printf("%d\n", inp_arr[i]);
    printf("\n");
}