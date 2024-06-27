#include <stdio.h>
#define SIZE 100

int stack[SIZE], choice, top;
void push(int x)
{
    stack[++top] = x;
}

int pop(void)
{
    return stack[top--];
}

void display(void)
{
    int i;
    if (top >= 0)
    {
        for (i = top; i >= 0; i--)
            printf("%d ", stack[i]);
    }
    else
    {
        printf("\n STACK Empty");
    }
}

int main()
{
    int i, num;
    top = -1;
    for (i = 1; i <= 3; i++)
    {
        scanf("%d", &num);
        push(num);
    }
    pop();
    display();

    return 0;
}
