/** 트리 1991 트리 순회 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
int lc[30];
int rc[30];

void preorder(int cur)
{
    cout << char(cur + 'A' - 1);
    if (lc[cur] != 0)
        preorder(lc[cur]);
    if (rc[cur] != 0)
        preorder(rc[cur]);
}

void inorder(int cur)
{
    if (lc[cur] != 0)
        inorder(lc[cur]);
    cout << char(cur + 'A' - 1);
    if (rc[cur] != 0)
        inorder(rc[cur]);
}

void postorder(int cur)
{
    if (lc[cur] != 0)
        postorder(lc[cur]);
    if (rc[cur] != 0)
        postorder(rc[cur]);
    cout << char(cur + 'A' - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char p, l, r;
        cin >> p >> l >> r;
        if (l != '.')
            lc[p - 'A' + 1] = l - 'A' + 1;
        if (r != '.')
            rc[p - 'A' + 1] = r - 'A' + 1;
    }

    preorder(1);
    cout << '\n';
    inorder(1);
    cout << '\n';
    postorder(1);
    cout << '\n';
}
