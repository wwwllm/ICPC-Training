#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    int m;
    cin >> m;
    vector T(11, vector<vector<int>>(11, vector<int>(26)));
    vector<string> c(m);
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        c[i] = s;
        int len = s.size();
        auto &tmp = T[len];
        for (int i = 0; i < len; i++)
        {
            tmp[i][s[i] - 'a'] = 1;
        }
    }
    for (auto s : c)
    {
        bool f = 1;
        if (s.size() != n)
            f = 0;
        for (int i = 0; f && i < n; i++)
        {
            int u = s[i] - 'a';
            if (T[a[i]][b[i] - 1][u] == 0)
                f = 0;
        }
        cout << (f ? "Yes\n" : "No\n");
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}