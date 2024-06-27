#include <stdio.h>
#define SIZE 100

int stack[SIZE], choice, top;
void push(int x);
int pop(void);
void display(void);

int main()
{

    top = -1;

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    display();

    pop();
    pop();

    display();

    return 0;
}

void push(int x)
{
    if (++top >= SIZE)
    {
        printf("Stack is full.\n");
        return;
    }
    stack[top] = x;
}

int pop()
{
    // 유효성 검사
    if (top <= -1)
    {
        printf("Stack is empty.\n");
        return -1;
    }

    return stack[top--];
}

void display()
{
    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);

    printf("\n");
}