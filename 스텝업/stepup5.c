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

    if (rear != NULL)
        rear->next = new_data;
    rear = new_data;

    if (front == NULL)
        front = new_data;
}

int dequeue()
{
    struct node *temp = front;
    if (front == NULL)
    {
        printf("\nUnderflow\n");
        return -1;
    }
    else
    {
        int temp_data = front->data;
        front = front->next;
        free(temp);
        return temp_data;
    }
}

void display()
{
    struct node *temp;
    if ((front == NULL) && (rear == NULL))
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        temp = front;
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{

    int i, num;
    for (i = 1; i <= 3; i++)
    {
        scanf("%d", &num);
        enqueue(num);
    }

    dequeue();
    display();

    return 0;
}