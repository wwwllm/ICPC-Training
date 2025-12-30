#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int pos = -1, l = -1, r = -1;
    for (int i = 1; i <= n; i++)
        if (g[i].size() == 3 || (g[i].size() == 2 && i == 1))
            pos = i;
        else if (g[i].size() == 1 && i != 1)
        {
            if (l == -1)
                l = i;
            else if (r == -1)
                r = i;
            else
            {
                cout << 0 << '\n';
                return;
            }
        }
    // cout << l << ' ' << r << '\n';
    if (pos == -1)
    {
        cout << exp(2, n) << '\n';
        return;
    }
    vector<int> dep(n + 1);
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        dep[u] = dep[fa] + 1;
        for (auto v : g[u])
        {
            if (v == fa)
                continue;
            self(self, v, u);
        }
    };
    dfs(dfs, 1, 0);
    int dl = dep[l], dr = dep[r], dp = dep[pos];
    // cout << dl << " " << dr << ' ' << dp << '\n';
    if (dl == dr)
        cout << (exp(2, dp) * 2) % mod << '\n';
    else
        cout << (exp(2, abs(dl - dr) + dp) + exp(2, abs(dl - dr) + dp - 1)) % mod << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}