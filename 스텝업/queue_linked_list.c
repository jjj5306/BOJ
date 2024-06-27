#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value)
{
    struct node *new_data = (node *)malloc(sizeof(node));
    new_data->data = value;
    new_data->next = NULL;
    if (front != NULL)
        front->next = new_data;
    front = new_data;
    if (rear == NULL)
        rear = new_data;
}

int dequeue()
{
    if (rear == NULL)
    {
        printf("Queue is empty.\n");
        return -1;
    }

    int rt = rear->data;
    struct node *tmp = rear;
    rear = rear->next;

    free(tmp);

    return rt;
}

void display()
{
    struct node *p = rear;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();

    dequeue();
    dequeue();
    display();

    return 0;
}