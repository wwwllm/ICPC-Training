#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://qoj.ac/contest/3729
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    vector adj(n + 1, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> f(n + 1, 1e9);
    f[1] = 0;
    vector<int> nxt(n + 1, 1e9);
    auto get_nxt = [&](auto self, int u, int fa) -> void
    {
        if (s[u] == '1')
            nxt[u] = 0;
        for (auto v : adj[u])
        {
            if (v == fa)
                continue;
            self(self, v, u);
            nxt[u] = min(nxt[v] + 1, nxt[u]);
        }
    };
    get_nxt(get_nxt, 1, 0);
    auto dfs = [&](auto &&self, int u, int fa, int w, int cur) -> void
    {
        for (auto v : adj[u])
        {
            if (v == fa)
                continue;
            w--;
            if (s[v] == '1')
                w = k;
            if (s[v] == '0')
                f[v] = cur + 1;
            else
                f[v] = cur;
            int ncur = cur;
            if (w == 0)
                w = k, ncur++;
            if (w <= nxt[v])
                w = max(w, k - nxt[v]);
            self(self, v, u, w, ncur);
        }
    };
    dfs(dfs, 1, 0, k, 0);
    for (int i = 2; i <= n; i++)
    {
        cout << f[i] << " \n"[i == n];
    }
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