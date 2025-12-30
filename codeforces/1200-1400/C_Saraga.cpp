#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2045/C
const int INF = 0x3f3f3f3f;
void solve()
{
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<int> p(26, INF);
    for (int i = 1; i < n; i++)
    {
        int u = a[i] - 'a';
        p[u] = min(p[u], i);
    }
    int len = INF, pos = INF;
    for (int i = m - 2; i >= 0; i--)
    {
        int u = b[i] - 'a';
        if (p[u] < n)
        {
            int l = p[u] + m - i;
            if (l < len)
            {
                len = l, pos = i;
            }
        }
    }
    if (len == INF)
        cout << -1 << '\n';
    else
    {
        int pp = p[b[pos] - 'a'];
        string ans1 = a.substr(0, pp);
        string ans2 = b.substr(pos);
        cout << ans1 + ans2 << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}