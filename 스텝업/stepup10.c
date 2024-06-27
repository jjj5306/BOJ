#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct Node
{ // 해시 테이블의 노드 구조체 정의
    int data;
    struct Node *next;
};

struct Hashtable
{ // 해시 테이블 구조체 정의
    struct Node *table[SIZE];
};

void initHashtable(struct Hashtable *hashtable)
{ // 해시 테이블 초기화 함수
    for (int i = 0; i < SIZE; i++)
    {
        hashtable->table[i] = NULL;
    }
}

int hashFunction(int key)
{ // 해시 함수: 값을 SIZE로 나눈 나머지에 매핑
    return key % SIZE;
}

// 해시 테이블에 데이터를 삽입하는 함수
void insert(struct Hashtable *hashtable, int data)
{
    int index = hashFunction(data);
    struct Node *newNode = (Node *)malloc(sizeof(Node));
    if (hashtable->tabletable[index] == NULL)
        newNode->next = NULL;
    else
        newNode->next = hashtable->table[index];

    newNode->data = data;
    hashtable->table[index] = newNode;
}

void displayHashtable(struct Hashtable *hashtable)
{ // 해시 테이블 출력 함수
    for (int i = 0; i < SIZE; i++)
    {
        struct Node *current = hashtable->table[i];
        printf("%d: ", i);
        while (current != NULL)
        {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    struct Hashtable hashtable;
    int i, n;
    initHashtable(&hashtable);
    for (i = 0; i < 10; i++)
    { // 데이터 입력 및 해시테이블 삽입
        scanf("%d", &n);
        insert(&hashtable, n);
    }
    displayHashtable(&hashtable); //  해시 테이블 출력
    return 0;
}
