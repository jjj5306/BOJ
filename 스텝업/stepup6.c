#include <stdio.h>
#include <stdlib.h>
int ans = 0;

struct TreeNode
{ // 이진 트리의 노드 구조체 정의
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
        return createNode(data); // 노드가 비어있으면 새로운 노드를 생성하여 반환} else {        if (data < root->data) {   // 데이터가 작으면 왼쪽 서브트리로 이동root->left = insertNode(root->left, data);}        else if (data > root->data) {   // 데이터가 크면 오른쪽 서브트리로 이동root->right = insertNode(root->right, data);}return root;}}int treeHeight(struct TreeNode* root) {   }
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

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int treeHeight(struct TreeNode *root, int height)
{
    // base condition
    if (root == NULL)
    {
        height--;
        ans = max(ans, height);
        return height;
    }
    treeHeight(root->left, height + 1);
    treeHeight(root->right, height + 1);
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
    treeHeight(root, 1);
    printf("%d", ans);
    return 0;
}
