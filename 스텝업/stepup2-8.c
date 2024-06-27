#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int data)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (newNode == NULL)
    {
        printf("error\n");
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
        return createNode(data); // 노드가 비어있으면 새로운 노드를 생성하여 반환
    }
    else
    {
        if (data < root->data)
        { // 데이터가 작으면 왼쪽 서브트리로 이동
            root->left = insertNode(root->left, data);
        }
        else if (data > root->data)
        { // 데이터가 크면 오른쪽 서브트리로 이동
            root->right = insertNode(root->right, data);
        }
        return root;
    }
}

int treeHeight(struct TreeNode *root)
{
    int leftHeight, rightHeight;
    if (root == NULL)
    {
        return 0; // 노드가 없으면 높이는 0
    }
    else
    {
        // 왼쪽 서브트리와 오른쪽 서브트리의 높이를 재귀적으로 구함
        leftHeight = treeHeight(root->left);
        rightHeight = treeHeight(root->right);
        // 더 큰 서브트리의 높이에 1을 더하여 반환
        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

int main()
{
    struct TreeNode *root = NULL;
    int data, height;
    for (int i = 0; i < 5; i++)
    { // 사용자로부터 5개의 데이터 입력받아 이진 트리에 삽입
        scanf("%d", &data);
        root = insertNode(root, data);
    }
    height = treeHeight(root);
    printf("%d", height);
    return 0;
}
