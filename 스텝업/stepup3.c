#include <stdio.h>
#include <stdlib.h>
struct Node
{ // 정수형 단일 연결 리스트의 노드 구조체 정의
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{ // 새로운 노드를 생성하는 함수
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

void insertSorted(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);
    if (head == NULL)
    {
        // 리스트가 빈 경우
        *head = newNode;
        printf("%d", *head->data);
        return;
    }

    // struct Node *before = NULL;
    // struct Node *next = head;
    // while (next != NULL)
    // {
    //     if (next->data > value)
    //     {
    //         // 삽입 시작
    //         if (before == NULL)
    //         {
    //             head->next = next;
    //             head = newNode;
    //         }
    //         else
    //         {
    //             before->next = newNode;
    //         }
    //         newNode->next = next;
    //     }
    //     before = next;
    //     next = next->next;
    // }
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
    struct Node *head = NULL; // 초기 리스트 생성 (오름차순으로 정렬되어 있음)
    insertSorted(&head, 10);
    printf("%d", head->data);
    printList(head);
    // insertSorted(head, 20);
    // printList(head);
    // insertSorted(head, 30);
    // insertSorted(head, 40);

    // int value;
    // scanf("%d", &value); // 삽입할 값 입력

    // insertSorted(head, value); // 사용자로부터 입력 받은 값을 리스트에 삽입
    // printList(head);
    return 0;
}
