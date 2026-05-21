#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://qoj.ac/contest/3729
void solve()
{
    int n;
    cin >> n;
    vector adj(1LL << n, vector<int>());
    for (int i = 1; i < (1LL << n); i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> siz(1LL << n), f(1LL << n, 0);
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        siz[u] = 1;
        for (auto v : adj[u])
        {
            if (v == fa)
                continue;
            self(self, v, u);
            siz[u] += siz[v];
            f[u] ^= (siz[v] * (siz[v] - 1) / 2) % 2;
        }
        if (u)
            f[u] ^= ((1LL << n) - 1 - siz[u]) * ((1LL << n) - 2 - siz[u]) / 2 % 2;
    };
    dfs(dfs, 0, -1);
    int ans = 0;
    for (int i = 0; i < (1LL << n); i++)
        if (!f[i])
            ans ^= i;
    cout << ans << '\n';
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