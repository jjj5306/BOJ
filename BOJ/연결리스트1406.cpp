/** 연결리스트 1406 에디터 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct node
{
    string data;
    node *left, *right;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    node *start, *before, *curser;
    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        node *new_node = new node;
        new_node->data = str[i];
        if (i == 0)
        {
            new_node->left = NULL;
            start = new_node;
            before = start;
        }
        else if (i == str.length() - 1)
        {
            new_node->left = before;
            before->right = new_node;
            new_node->right = NULL;
            before = new_node;
        }
        else
        {
            before->right = new_node;
            new_node->left = before;
            before = new_node;
        }
    }

    // 노드 마지막에 널 문자 느낌으로 추가
    node *last_node = new node;
    curser = last_node;
    before->right = last_node;
    last_node->data = "last";
    last_node->left = before;
    last_node->right = NULL;
    curser = last_node;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "L")
        {
            if (curser->left != NULL)
                curser = curser->left;
        }
        else if (cmd == "D")
        {
            if (curser->right != NULL)
                curser = curser->right;
        }
        else if (cmd == "B")
        {
            if (curser->left != NULL)
            {
                // 커서 왼쪽 문자 삭제
                node *tmp = curser->left;
                if (curser->left->left != NULL)
                {
                    curser->left->left->right = curser;
                    curser->left = curser->left->left;
                }
                else
                {
                    curser->left = NULL;
                    start = curser;
                }
                delete tmp;
            }
        }
        else
        {
            char new_ch;
            cin >> new_ch;
            node *new_node = new node;
            new_node->data = new_ch;
            if (curser->left == NULL)
            {
                curser->left = new_node;
                new_node->left = NULL;
                new_node->right = curser;
                start = new_node;
            }
            else
            {
                new_node->left = curser->left;
                new_node->right = curser;
                curser->left->right = new_node;
                curser->left = new_node;
            }
        }
    }

    // 출력
    node *current = start;
    while (current != NULL && current->data != "last")
    {
        cout << current->data;
        current = current->right;
    }
    cout << '\n';
}
