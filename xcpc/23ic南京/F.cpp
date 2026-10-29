#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector<int>());
    vector<int> res(m + 1);
    for (int i = 1; i <= n; i++)
    {
        int siz;
        cin >> siz;
        for (int j = 0; j < siz; j++)
        {
            int pos;
            cin >> pos;
            res[pos] = i;
            g[i].push_back(pos);
        }
    }
    vector adj(n + 1, vector<int>());
    for (int i = 1; i <= n; i++)
    {
        for (auto u : g[i])
        {
            if (res[u] != i)
                adj[i].push_back(res[u]);
        }
        ranges::sort(adj[i]);
    }
    bool ok = 0;
    vector<int> ans(n + 1);
    ranges::iota(ans, 0);
    for (int i = 1; i < n; i++)
    {
        if (adj[i].empty() || adj[i][0] != i + 1)
        {
            if (ok == 0)
            {
                swap(ans[i], ans[i + 1]);
            }
            ok = 1;
        }
    }
    cout << (ok ? "Yes\n" : "No\n");
    if (ok)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i];
            if (i == n)
                cout << '\n';
            else
                cout << ' ';
        }
    }
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