#include <bits/stdc++.h>
using namespace std;

using u64 = unsigned long long;
using i64 = long long;
const int inf = 1e9;
int randINT(int l, int r)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(l, r);
    return distrib(gen);
}
void solve()
{
    int n, m;
    i64 sum;
    cin >> n >> m >> sum;
    vector adj(n + 1, vector<int>()), radj(n + 1, vector<int>());
    vector<i64> val(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    vector dist(n + 1, vector<int>(n + 1, inf));
    auto bfs = [&](int s)
    {
        auto &dis = dist[s];
        dis[s] = 0;
        queue<int> q;
        q.push(s);
        while (q.size())
        {
            auto u = q.front();
            q.pop();
            for (auto v : adj[u])
            {
                if (dis[v] != inf)
                    continue;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    };
    for (int i = 1; i <= n; i++)
    {
        bfs(i);
    }
    int len = dist[1][n];
    if (dist[1][n] == inf)
    {
        cout << 0 << '\n';
        return;
    }
    vector<u64> f(n + 1), g(n + 1);
    vector dep(n + 1, vector<int>());
    for (int u = 1; u <= n; u++)
    {
        if (dist[1][u] + dist[u][n] == len)
        {
            dep[dist[1][u]].push_back(u);
        }
    }
    f[1] = 1;
    for (int d = 0; d <= len; d++)
    {
        for (auto u : dep[d])
        {
            for (auto v : adj[u])
            {
                if (dist[1][v] != d + 1 || dist[1][v] + dist[v][n] != len)
                    continue;
                f[v] += f[u];
                f[v] = min(f[v], (u64)1e18);
            }
        }
    }
    g[n] = 1;
    for (int d = len; d >= 0; d--)
    {
        for (auto u : dep[d])
        {
            for (auto v : adj[u])
            {
                if (dist[1][v] != d + 1 || dist[1][v] + dist[v][n] != len)
                    continue;
                g[u] += g[v];
                g[u] = min(g[u], (u64)1e18);
            }
        }
    }
    int ll;
    u64 mi = ULLONG_MAX;
    for (int d = 0; d <= len; d++)
    {
        u64 cur = 0;
        for (auto u : dep[d])
        {
            cur += f[u];
            cur = min(cur, (u64)1e18);
            cur += g[u];
            cur = min(cur, (u64)1e18);
        }
        if (cur < mi)
        {
            ll = d;
            mi = cur;
        }
    }
    vector cnt(n + 1, vector<i64>());
    auto dfs1 = [&](auto &&self, int u, int l, i64 cost) -> void
    {
        if (cost > sum)
            return;
        if (l == ll)
        {
            cnt[u].push_back(cost);
            return;
        }
        for (auto v : adj[u])
        {
            int d = l + 1;
            if (dist[1][v] != d || (dist[1][v] + dist[v][n] != len))
                continue;
            self(self, v, l + 1, cost + val[v]);
        }
    };
    dfs1(dfs1, 1, 0, val[1]);
    u64 ans = 0;
    vector pos(n + 1, vector<i64>());
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i].empty())
            continue;
        ranges::sort(cnt[i]);
    }
    vector cnt1(n + 1, vector<i64>());
    auto dfs2 = [&](auto &&self, int u, int l, i64 cost) -> void
    {
        if (cost > sum)
            return;
        if (l == len - ll)
        {
            cnt1[u].push_back(cost - val[u]);
            return;
        }
        for (auto v : radj[u])
        {
            int d = l + 1;
            if (d != dist[v][n] || (dist[1][v] + dist[v][n] != len))
                continue;
            self(self, v, l + 1, cost + val[v]);
        }
    };
    dfs2(dfs2, n, 0, val[n]);
    for (int i = 1; i <= n; i++)
    {
        if (cnt1[i].empty())
            continue;
        ranges::sort(cnt1[i], greater<i64>());
        int m = cnt1[i].size();
        int siz = cnt[i].size();
        for (int j = 0, k = 0; j < m; j++)
        {
            while (k < siz && cnt[i][k] + cnt1[i][j] <= sum)
                k++;
            ans += (u64)k;
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}