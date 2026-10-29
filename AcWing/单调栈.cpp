#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int s[maxn], top = 0, a[maxn], ans[maxn]; // 严格单调增
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    s[++top] = 1, a[0] = -1;
    for (int i = 2; i <= n; i++)
    {
        while (a[i] <= a[s[top]] && top > 0)
        {
            ans[s[top]] = s[top - 1];
            top--;
        }
        s[++top] = i;
    }
    while (top > 0)
    {
        ans[s[top]] = s[top - 1];
        top--;
    }
    for (int i = 1; i <= n; i++)
        cout << a[ans[i]] << ' ';
    cout << endl;
    return 0;
}
