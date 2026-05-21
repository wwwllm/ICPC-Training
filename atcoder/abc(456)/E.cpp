#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> e(m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        e[i] = {u, v};
    }
    int w;
    vector<string> s(n);
    cin >> w;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    vector adj(n * w, vector<int>());
    for (auto [u, v] : e)
    {
        for (int i = 0; i < w; i++)
        {
            if (s[u][i] == 'o' && s[v][(i + 1) % w] == 'o')
            {
                int uu = i * n + u, vv = (i + 1) % w * n + v;
                adj[uu].push_back(vv);
            }
            if (s[v][i] == 'o' && s[u][(i + 1) % w] == 'o')
            {
                int vv = i * n + v, uu = (i + 1) % w * n + u;
                adj[vv].push_back(uu);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] == 'o' && s[i][(j + 1) % w] == 'o')
            {
                int u = j * n + i, v = (j + 1) % w * n + i;
                adj[u].push_back(v);
            }
        }
    }
    queue<int> q;
    vector<int> ind(n * w);
    for (int i = 0; i < n * w; i++)
    {
        for (auto v : adj[i])
            ind[v]++;
    }
    for (int i = 0; i < n * w; i++)
    {
        if (ind[i] == 0)
            q.push(i);
    }
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (ind[v] == 0)
                continue;
            ind[v]--;
            if (ind[v] == 0)
                q.push(v);
        }
    }
    for (int i = 0; i < n * w; i++)
    {
        if (ind[i])
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}