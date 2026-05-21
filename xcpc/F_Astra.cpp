#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://qoj.ac/contest/3588
void solve()
{
    int n, k;
    cin >> n >> k;
    vector adj(n + 1, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector dp(n + 1, vector<int>(n + 1, -1));
    auto sg = [&](auto &&self, int u, int f) -> int
    {
        if (dp[f][u] != -1)
            return dp[f][u];
        int s = 0;
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            s ^= self(self, v, u);
        }
        set<int> S;
        auto dfs = [&](auto &&dfs, int u, int fa, int cur, int dep) -> void
        {
            int s = 0;
            for (auto v : adj[u])
            {
                if (v == fa)
                    continue;
                s ^= self(self, v, u);
            }
            S.insert(s ^ cur);
            if (dep < k)
            {
                for (auto v : adj[u])
                {
                    if (v == fa)
                        continue;
                    int ncur = cur ^ s ^ self(self, v, u);
                    dfs(dfs, v, u, ncur, dep + 1);
                }
            }
        };
        dfs(dfs, u, f, 0, 1);
        int mex = 0;
        for (auto x : S)
        {
            if (x == mex)
            {
                mex++;
            }
            else
                break;
        }
        return dp[f][u] = mex;
    };
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        int s = 0;
        for (auto v : adj[i])
        {
            s ^= sg(sg, v, i);
        }
        if (s > 0)
            cout << "1";
        else
            cout << "0";
    }
    cout << '\n';
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