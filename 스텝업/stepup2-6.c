#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;
} Stack;

Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("error\n");
        exit(0);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

void initStack(Stack *stack)
{
    stack->top = NULL;
}

int isEmpty(Stack *stack)
{
    return stack->top == NULL;
}

void push(Stack *stack, int data)
{
    Node *node = newNode(data);
    node->next = stack->top;
    stack->top = node;
}

void pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("error\n");
        return;
    }
    Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("error\n");
        return -1;
    }
    return stack->top->data;
}

void freeStack(Stack *stack)
{
    while (!isEmpty(stack))
    {
        pop(stack);
    }
}

int main()
{
    Stack stack;
    int i, num;
    initStack(&stack);
    for (i = 1; i <= 3; i++)
    {
        scanf("%d", &num);
        push(&stack, num);
    }
    pop(&stack);
    printf("%d\n", peek(&stack));
    freeStack(&stack);
    return 0;
}
