#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n;
    cin >> n;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    vector adj(n + 1, vector<int>());
    int root = -1;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        if (root == -1)
            root = u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> son(n + 1), sz(n + 1);
    auto get_son = [&](auto &&self, int u, int f) -> void
    {
        sz[u] = 1;
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            self(self, v, u);
            sz[u] += sz[v];
            if (sz[son[u]] < sz[v])
                son[u] = v;
        }
    };
    get_son(get_son, root, 0);
    int flag = 0, sum = 0, ma = 0;
    vector<int> cnt(n + 1), ans(n + 1);
    auto update = [&](int u, int val)
    {
        cnt[c[u]] += val;
        if (cnt[c[u]] > ma)
        {
            ma = cnt[c[u]];
            sum = c[u];
        }
        else if (cnt[c[u]] == ma)
            sum += c[u];
    };
    auto init = [&]()
    { sum = 0, ma = 0; };
    auto count = [&](auto &&self, int u, int f, int val) -> void
    {
        update(u, val);
        for (auto v : adj[u])
        {
            if (v == f || v == flag)
                continue;
            self(self, v, u, val);
        }
    };
    auto dfs = [&](auto &&self, int u, int f, bool keep) -> void
    {
        for (auto v : adj[u])
        {
            if (v == son[u] || v == f)
                continue;
            self(self, v, u, 0);
        }
        if (son[u])
        {
            self(self, son[u], u, 1);
            flag = son[u];
        }
        count(count, u, f, 1);
        flag = 0;
        ans[u] = sum;
        if (!keep)
        {
            count(count, u, f, -1);
            init();
        }
    };
    dfs(dfs, root, 0, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
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