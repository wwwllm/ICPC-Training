#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18, N = 20;
void solve()
{
    int L, R;
    cin >> L >> R;
    int cur = 0;
    vector<int> p2(N + 1);
    int s, t;
    t = p2[0] = cur++;
    vector adj(300, vector<array<int, 2>>());
    for (int i = 1; i <= N; i++)
    {
        p2[i] = cur++;
        adj[p2[i]].push_back({p2[i - 1], 0});
        adj[p2[i]].push_back({p2[i - 1], 1});
    }
    s = cur++;
    int l = s;
    auto dfs = [&](auto &&self, int p, int bit, int zero, int up, int down) -> void
    {
        if (!up && !down)
        {
            adj[p].push_back({p2[bit], 1});
            adj[p].push_back({p2[bit], 0});
            return;
        }
        int r = up ? (R >> bit & 1) : 1;
        int l = down ? (L >> bit & 1) : 0;
        for (int u = l; u <= r; u++)
        {
            int np;
            if (zero | u)
            {
                if (bit == 0)
                    np = t;
                else
                    np = cur++;
            }
            else
                np = p;
            if (np != p)
            {
                adj[p].push_back({np, u});
            }
            if (bit != 0)
                self(self, np, bit - 1, zero | u, up & (u == r), down & (u == l));
        }
    };
    dfs(dfs, s, 20, 0, 1, 1);
    vector<int> id(cur, -1);
    vector<int> vis(l);
    vis[0] = 1;
    for (int u = l; u < cur; u++)
    {
        for (auto [v, w] : adj[u])
        {
            if (v < l)
                vis[v] = 1;
        }
    }
    for (int i = N - 1; i >= 0; i--)
    {
        vis[i] |= vis[i + 1];
    }
    int cnt = 0;
    for (int i = 0; i < cur; i++)
    {
        if (i < l && vis[i] == 0)
            continue;
        id[i] = ++cnt;
    }
    cout << cnt << '\n';
    for (int i = 0; i < cur; i++)
    {
        if (id[i] == -1)
            continue;
        vector<array<int, 2>> e;
        for (auto [v, w] : adj[i])
        {
            if (id[v] == -1)
                continue;
            e.push_back({id[v], w});
        }
        cout << e.size() << ' ';
        for (auto [v, w] : e)
        {
            cout << v << ' ' << w << ' ';
        }
        cout << '\n';
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