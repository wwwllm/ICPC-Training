#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector adj(n + 1, vector<int>());
    vector<int> ind(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        ind[v]++;
        adj[u].push_back(v);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
            q.push(i);
    }
    vector<int> rank;
    while (q.size())
    {
        auto u = q.front();
        q.pop();
        rank.push_back(u);
        for (auto v : adj[u])
        {
            ind[v]--;
            if (ind[v] == 0)
                q.push(v);
        }
    }
    if (rank.size() == n)
    {
        cout << 1 << '\n';
        for (auto u : rank)
            cout << u << ' ';
        cout << '\n';
    }
    else
    {
        cout << 2 << '\n';
        for (int i = 1; i <= n; i++)
        {
            cout << i << " \n"[i == n];
        }
        for (int i = n; i >= 1; i--)
        {
            cout << i << " \n"[i == n];
        }
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