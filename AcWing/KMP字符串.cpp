#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, m;
    string s, p;
    cin >> n >> p >> m >> s;
    vector<int> ne(n + 1);
    s = '0' + s;
    p = '0' + p;
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }
    for (int i = 1, j = 0; i <= m; i++)
    {
        while (j && s[i] != p[j + 1])
            j = ne[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == n)
        {
            cout << i - n << ' ';
            j = ne[j];
        }
    }
    return 0;
}