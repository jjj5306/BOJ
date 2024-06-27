#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{ // 이진 탐색 트리의 노드 구조체 정의
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int data)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (newNode == NULL)
    {
        printf("메모리 할당 오류\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode *insertNode(struct TreeNode *root, int data)
{
    if (root == NULL)
    {
        return createNode(data); // 노드가 비어있으면 새로운 노드를 생성하여 반환}
    }
    else
    { // 데이터가 작으면 왼쪽 서브트리로 이동
        if (data < root->data)
        {
            root->left = insertNode(root->left, data);
        } // 데이터가 크면 오른쪽 서브트리로 이동
        else if (data > root->data)
        {
            root->right = insertNode(root->right, data);
        }
        return root;
    }
}

// 이진 탐색 트리를 탐색하여 특정 데이터를 찾는 함수
struct TreeNode *searchNode(struct TreeNode *root, int key)
{
    if (root == NULL)
        return NULL;
    else if (root->data == key)
        return root;
    else if (root->data > key)
        searchNode(root->left, key);
    else
        searchNode(root->right, key);
}

int main()
{
    struct TreeNode *root = NULL;
    int data, key;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &data);
        root = insertNode(root, data);
    }
    scanf("%d", &key); // 탐색하려는 정수 입력
    struct TreeNode *result = searchNode(root, key);
    if (result != NULL)
    {
        printf("found");
    }
    else
    {
        printf("not found");
    }
    return 0;
}
