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
        printf("error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 정렬된 단일 연결 리스트에 값을 삽입하는 함수
void insertSorted(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *current = *head;
    struct Node *prev = NULL;

    // 리스트가 비어있거나 첫 번째 노드의 값보다 클 경우
    if (*head == NULL || (*head)->data >= data)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // 중간에 노드를 삽입해야 할 경우
    while (current != NULL && current->data < data)
    {
        prev = current;
        current = current->next;
    }
    newNode->next = current;
    prev->next = newNode;
}

void printList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main()
{
    int value;
    struct Node *head = NULL;

    // 초기 리스트 생성 (오름차순으로 정렬되어 있음)
    insertSorted(&head, 10);
    insertSorted(&head, 20);
    insertSorted(&head, 30);
    insertSorted(&head, 40);

    scanf("%d", &value);        // 삽입할 값 입력
    insertSorted(&head, value); // 사용자로부터 입력 받은 값을 리스트에 삽입

    printList(head);

    return 0;
}
