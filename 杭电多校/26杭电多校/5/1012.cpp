#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353, N = 2e5;
vector<int> P(N + 1), PP(N + 1);
void init()
{
    P[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        P[i] = P[i - 1] * i % mod;
    }
    PP[1] = 1, PP[0] = 1;
    for (int i = 2; i <= N; i++)
    {
        PP[i] = PP[i - 2] * i % mod;
    }
}
void solve()
{
    int n;
    cin >> n;
    vector e(n + 1, vector<array<int, 2>>());
    for (int i = 1; i < n; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        e[c].push_back({u, v});
    }
    vector<int> vis(n + 1), dp(n + 1);
    vector adj(n + 1, vector<int>());
    int ans = 1;
    for (int len = 2; len <= n; len++)
    {
        if (e[len].empty())
            continue;
        vector<int> p;
        for (auto [u, v] : e[len])
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
            p.push_back(v);
            p.push_back(u);
        }
        ranges::sort(p);
        p.erase(unique(p.begin(), p.end()), p.end());
        auto dfs = [&](auto &&self, int u, int f) -> int
        {
            vis[u] = 1;
            dp[u] = 0;
            int res = 1;
            for (auto v : adj[u])
            {
                if (v == f)
                    continue;
                int val = self(self, v, u);
                if (val == 0)
                    return 0;
                (res *= val) %= mod;
            }
            unordered_map<int, int> mp;
            for (auto v : adj[u])
            {
                if (v == f)
                    continue;
                int l = dp[v] + 1;
                if (l > len - 1)
                    return 0;
                if (l < len - 1)
                    mp[l]++;
            }
            for (auto [l1, x] : mp)
            {
                int l2 = len - l1 - 1;
                if (l1 == l2)
                {
                    (res *= PP[(x + 1) / 2 * 2 - 1]) %= mod;
                    if (x & 1)
                    {
                        if (dp[u] != 0)
                            return 0LL;
                        dp[u] = l1;
                    }
                }
                if (!mp.count(l2))
                {
                    if (x > 1 || (x == 1 && dp[u] != 0))
                        return 0;
                    if (x == 1 && dp[u] == 0)
                    {
                        dp[u] = l1;
                    }
                    continue;
                }
                if (l1 < l2)
                {
                    int y = mp[l2];
                    if (abs(x - y) > 1 || (dp[u] != 0 && abs(x - y) == 1))
                        return 0;
                    if (x > y)
                        dp[u] = l1;
                    else if (y > x)
                        dp[u] = l2;
                    (res *= P[max(x, y)]) %= mod;
                }
            }
            return res;
        };
        for (auto u : p)
        {
            if (vis[u] == 0)
            {
                (ans *= dfs(dfs, u, 0)) %= mod;
                if (dp[u] != 0 || ans == 0)
                {
                    cout << "0\n";
                    return;
                }
            }
        }
        for (auto u : p)
        {
            vis[u] = 0;
            dp[u] = 0;
            adj[u].clear();
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}