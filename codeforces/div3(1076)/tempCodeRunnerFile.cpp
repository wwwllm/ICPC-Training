#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    auto query = [&](int x, int y) -> bool
    {
        cout << "? " << x << ' ' << y << endl;
        bool res;
        cin >> res;
        return res;
    };
    auto answer = [&](int x)
    {
        cout << "! " << x << endl;
    };
    int n;
    cin >> n;
    vector adj(n + 1, vector<int>{});
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> p;
    function<void(int, int)> dfs = [&](int u, int f)
    {
        p.pb(u);
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            dfs(v, u);
        }
    };

    dfs(1, 0);
    for (int i = 0; i < n; i += 2)
    {
        int u = p[i], v = p[i + 1];
        auto res = query(u, v);
        if (res)
        {
            res = query(u, u);
            if (res)
                answer(u);
            else
                answer(v);
            return;
        }
    }
    answer(*p.rbegin());
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