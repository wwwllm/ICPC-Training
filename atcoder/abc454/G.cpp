#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18, mod = 998244353;
void solve()
{
    int n, seed, m, f;
    cin >> n >> seed >> m >> f;
    vector<int> q(m + 1), d(m + 1), c(n + 1);
    for (int i = 2; i <= m; i++)
        cin >> q[i];
    for (int i = 1; i <= m; i++)
        cin >> d[i];
    vector adj(n + 1, vector<int>());
    vector<int> p(n + 1, 0);
    int root = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i <= m)
        {
            p[i] = q[i];
            adj[p[i]].push_back(i);
        }
        else
        {
            p[i] = seed % (i - 1) + 1;
            adj[p[i]].push_back(i);
            seed = (seed * 1103515245 + 12345) % (1LL << 31);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i <= m)
        {
            c[i] = d[i];
        }
        else
        {
            c[i] = seed % (f) + 1;
            seed = (seed * 1103515245 + 12345) % (1LL << 31);
        }
    }
    vector<int> son(n + 1), sz(n + 1);
    auto get_son = [&](auto &&self, int u) -> void
    {
        sz[u] = 1;
        for (auto v : adj[u])
        {
            self(self, v);
            sz[u] += sz[v];
            if (sz[son[u]] < sz[v])
                son[u] = v;
        }
    };
    get_son(get_son, root);
    vector<int> cnt(n + 1);
    int sum = 0, ma = 0, flag = 0, ans = 0;
    auto init = [&]()
    { sum = 0, ma = 0; };
    auto update = [&](int u, int val)
    {
        cnt[c[u]] += val;
        if (cnt[c[u]] > ma)
        {
            sum = 1;
            ma = cnt[c[u]];
        }
        else if (cnt[c[u]] == ma)
            sum++;
    };
    auto count = [&](auto &&self, int u, int val) -> void
    {
        update(u, val);
        for (auto v : adj[u])
        {
            if (v == flag)
                continue;
            self(self, v, val);
        }
    };
    auto dfs = [&](auto &&self, int u, bool keep) -> void
    {
        for (auto v : adj[u])
        {
            if (v == son[u])
                continue;
            self(self, v, 0);
        }
        if (son[u])
            self(self, son[u], 1), flag = son[u];
        count(count, u, 1);
        flag = 0;
        (ans += (ma ^ u) * (sum ^ u) % mod) %= mod;
        if (!keep)
        {
            count(count, u, -1);
            init();
        }
    };
    dfs(dfs, root, 0);
    cout << ans << '\n';
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