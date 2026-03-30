#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> val(n + 1);
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if (c == 'R')
            val[i] = 0;
        else if (c == 'G')
            val[i] = 1;
        else
            val[i] = 2;
    }
    vector<int> st(n + 1);
    vector adj(n + 1, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    function<void(int, int)> dfs = [&](int u, int f)
    {
        st[u] = 1;
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            if (val[u] == val[v])
                dfs(v, u);
        }
    };
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        if (st[i] == 0)
        {
            c++;
            dfs(i, 0);
        }
    }
    if (c <= 2)
    {
        cout << 0 << '\n';
        return;
    }
    queue<int> q;
    vector<int> f(n + 1), vis(n + 1), deg(n + 1);
    for (int i = 1; i <= n; i++)
    {
        deg[i] = adj[i].size();
        if (adj[i].size() == 1)
        {
            q.push(i);
        }
    }
    int cnt = n;
    while (q.size())
    {
        auto u = q.front();
        q.pop();
        if (f[u])
            continue;
        cnt--;
        vis[u] = 1;
        for (auto v : adj[u])
        {
            if (vis[v])
                continue;
            if (val[u] != val[v])
                f[v] = 1;
            deg[v]--;
            if (deg[v] == 1 && !f[v])
                q.push(v);
        }
    }
    cout << cnt << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}