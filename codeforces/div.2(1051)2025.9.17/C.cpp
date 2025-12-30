#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int inf = 1e18;
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> ind(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        if (x > y)
        {
            g[u].pb(v);
            ind[v]++;
        }
        else
        {
            g[v].pb(u);
            ind[u]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
            q.push(i);
    }
    vector<int> res(n + 1);
    int idx = n;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        res[u] = idx--;
        for (auto v : g[u])
        {
            ind[v]--;
            if (ind[v] == 0)
            {
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << " \n"[i == n];
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