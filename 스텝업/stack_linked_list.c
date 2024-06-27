#include <stdio.h>
#include <stdlib.h>

void push(int);
int pop();
void print_s();

typedef struct node
{
    int data;
    struct node *next;
} stack;

stack *top = NULL;

int main()
{

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    print_s();

    pop();
    pop();
    print_s();
}

void push(int data)
{
    stack *new_data = (stack *)malloc(sizeof(stack));
    new_data->data = data;
    new_data->next = top;

    top = new_data;
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack is full.\n");
        return -1;
    }

    int rt = top->data;
    stack *tmp = top;
    top = top->next;
    free(tmp);

    return rt;
}

void print_s()
{
    stack *tmp = top;
    while (tmp != NULL)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}