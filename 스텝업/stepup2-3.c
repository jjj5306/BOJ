#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int searchNode(struct Node **head, int value)
{
    struct Node *current = *head;
    while (current != NULL)
    {
        if (current->data == value)
        {
            return 1; // 값이 리스트에 존재함
        }
        current = current->next;
    }
    return 0; // 값이 리스트에 존재하지 않음
}

int main()
{
    int value, found;
    struct Node *head = NULL;
    struct Node *node = NULL;
    struct Node *tail = NULL;

    // 초기 리스트 생성 (오름차순으로 정렬되어 있음)
    for (int i = 1; i <= 5; i++)
    {
        node = createNode(i);
        if (head == NULL)
        {
            head = node;
            tail = head;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    // 사용자로부터 입력 받은 값을 리스트에서 탐색
    scanf("%d", &value);
    found = searchNode(&head, value);
    printf("%d", found);

    return 0;
}
