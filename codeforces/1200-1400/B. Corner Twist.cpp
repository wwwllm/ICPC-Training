#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/1983/B
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(n);
    for (auto &s : a)
        cin >> s;
    for (auto &s : b)
        cin >> s;
    bool ok = 1;
    for (int i = 0; i < n; i++)
    {
        int suma = 0, sumb = 0;
        for (int j = 0; j < m; j++)
        {
            int u = a[i][j] - '0', v = b[i][j] - '0';
            suma = (suma + u) % 3;
            sumb = (sumb + v) % 3;
        }
        ok &= (suma == sumb);
    }
    for (int j = 0; j < m; j++)
    {
        int suma = 0, sumb = 0;
        for (int i = 0; i < n; i++)
        {

            int u = a[i][j] - '0', v = b[i][j] - '0';
            suma = (suma + u) % 3;
            sumb = (sumb + v) % 3;
        }
        ok &= (suma == sumb);
    }
    cout << (ok ? "YES\n" : "NO\n");
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}