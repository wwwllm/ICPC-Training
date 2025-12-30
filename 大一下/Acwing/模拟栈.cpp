#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
int st[maxn];
int top = -1;
int n;
int main()
{
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            int a;
            cin >> a;
            st[++top] = a;
        }
        if (s == "pop")
        {
            top--;
        }
        if (s == "query")
        {
            cout << st[top] << endl;
        }
        if (s == "empty")
        {
            cout << (top == -1 ? "YES" : "NO") << endl;
        }
    }
}