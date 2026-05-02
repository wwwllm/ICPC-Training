#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector pos(n + 1, vector<int>());
    for (int i = 1; i <= n; i++)
        cin >> a[i],
            pos[a[i]].push_back(i);
    vector adj(n + 1, vector<int>());
    vector<int> ind(n + 1);
    for (int i = 1; i <= n; i++)
    {
        adj[i].push_back(a[i]);
        ind[a[i]]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
            q.push(i);
    }
    vector dp(n + 1, vector<int>(n + 1, 1));
    while (q.size())
    {
        auto u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            ind[v]--;
            for (int i = 1; i <= n; i++)
            {
                int res = 0;
                for (auto idx : pos[i])
                {
                    res += dp[u][idx];
                    res %= mod;
                }
                dp[v][i] = dp[v][i] * res % mod;
            }
            if (ind[v] == 0)
                q.push(v);
        }
    }
    auto calc = [&](int s) -> int
    {
        vector<int> cycle;
        int p = s;
        while (ind[p])
        {
            ind[p]--;
            cycle.push_back(p);
            p = a[p];
        }
        int len = cycle.size();
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            int cur = i;
            for (int j = 0; j < len; j++)
            {
                cur = a[cur];
            }
            if (cur != i)
                continue;
            cur = i;
            int cnt = 1;
            for (int j = 0; j < len; j++)
            {
                cnt = cnt * dp[cycle[j]][cur] % mod;
                cur = a[cur];
            }
            res += cnt;
            res %= mod;
        }
        return res;
    };
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (ind[i])
        {
            ans *= calc(i);
            ans %= mod;
        }
    }
    cout << ans << '\n';
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