/** ��� 17478 ����Լ��� ������? **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int k;

void chat_(int n)
{
    for (int i = 0; i < n; i++)
        cout << "____";
}

void chat(int n)
{
    chat_(n);
    cout << "\"����Լ��� ������?\"\n";
    if (n == k)
    {
        chat_(n);
        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
        chat_(n);
        cout << "��� �亯�Ͽ���.\n";
        return;
    }
    chat_(n);
    cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
    chat_(n);
    cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
    chat_(n);
    cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";

    chat(n + 1);

    chat_(n);
    cout << "��� �亯�Ͽ���.\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    chat(0);
}
