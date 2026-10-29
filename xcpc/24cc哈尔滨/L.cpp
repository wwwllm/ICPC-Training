#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            (ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}
int inv(int x)
{
    return exp(x, mod - 2);
}
void solve()
{
    int n;
    cin >> n;
    vector adj(n, vector<int>());
    int q = inv(n * (n - 1) / 2 % mod);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> fa(n), siz(n), p(n);
    auto dfs1 = [&](auto &&self, int u, int f) -> void
    {
        siz[u] = 1;
        fa[u] = f;
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            self(self, v, u);
            siz[u] += siz[v];
        }
        p[u] = exp(siz[u] * (n - siz[u]) % mod, 2);
    };
    dfs1(dfs1, 0, -1);
    vector<int> sum1(n), sum2(n), f(n);
    auto dfs2 = [&](auto &&self, int u) -> void
    {
        sum1[u] = siz[u] * siz[u] % mod;
        for (auto v : adj[u])
        {
            if (v == fa[u])
                continue;
            self(self, v);
            (sum1[u] += sum1[v]) %= mod;
            (sum2[u] += sum1[v]) %= mod;
        }
        f[u] = 2 * sum2[u] * (n - siz[u]) % mod * (n - siz[u]) % mod;
        for (auto v : adj[u])
        {
            if (v == fa[u])
                continue;
            (f[u] += (sum2[u] - sum1[v] + mod) % mod * sum1[v] % mod) %= mod;
        }
    };
    dfs2(dfs2, 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        (ans += (p[i] + f[i]) % mod) %= mod;
    }
    cout << ans * exp(q, 2) % mod << '\n';
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