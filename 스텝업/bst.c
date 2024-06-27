#include <stdio.h>
#include <stdlib.h>

typedef struct NodeStruct
{
    int value;
    struct NodeStruct *leftChild;
    struct NodeStruct *rightChild;
} Node;
Node *root = NULL;

Node *BST_insert(Node *root, int value)
{
    if (root == NULL)
    {
        // base condition : 리프 노드에 도달하면 삽입
        root = (Node *)malloc(sizeof(Node));
        root->leftChild = root->rightChild = NULL;
        root->value = value;
        return root;
    }
    else
    {
        if (root->value > value)
        {
            root->leftChild = BST_insert(root->leftChild, value);
        }
        else if (root->value < value)
        {
            root->rightChild = BST_insert(root->rightChild, value);
        }
    }
    return root;
}

Node *findMinNode(Node *root)
{
    Node *tmp = root;
    while (tmp->leftChild != NULL)
        tmp = tmp->leftChild;
    return tmp;
}

Node *BST_delete(Node *root, int value)
{
    Node *tNode = NULL;
    if (root == NULL)
        return NULL;
    if (root->value > value)
        root->leftChild = BST_delete(root->leftChild, value);
    else if (root->value < value)
        root->rightChild = BST_delete(root->rightChild, value);
    else
    {
        // 자식 노드가 둘 다 있을 경우
        if (root->rightChild != NULL && root->leftChild != NULL)
        {
            tNode = findMinNode(root->rightChild);
            root->value = tNode->value;
            root->rightChild = BST_delete(root->rightChild, tNode->value);
        }
        else
        {
            tNode = (root->leftChild == NULL) ? root->rightChild : root->leftChild;
            free(root);
            return tNode;
        }
    }

    return root;
}

Node *BST_search(Node *root, int value)
{
    // value 찾기
    if (root->value == value)
        return root;
    else
    {
        if (root->value > value)
            BST_search(root->leftChild, value);
        else
            BST_search(root->rightChild, value);
    }
}

void BST_print(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->value);
    BST_print(root->leftChild);
    BST_print(root->rightChild);
}

int main()
{
    Node *result;
    root = BST_insert(root, 5);
    root = BST_insert(root, 3);
    root = BST_insert(root, 7);
    root = BST_insert(root, 1);
    root = BST_insert(root, 9);
    root = BST_insert(root, 6);

    root = BST_delete(root, 7);

    result = BST_search(root, 9);

    if (result != NULL)
        printf("%d \n", result->value);

    BST_print(root);
}