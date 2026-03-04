#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector adj(n + 1, vector<int>{});
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> sum(n + 1), f(n + 1), pre(n + 1), dis(n + 1), dism(n + 1);
    dis[0] = -1;
    function<void(int, int)> get_info = [&](int u, int fa)
    {
        pre[u] = fa;
        sum[u] = a[u];
        dis[u] = dis[fa] + 1;
        dism[u] = dis[u];
        for (auto v : adj[u])
        {
            if (v == fa)
                continue;
            get_info(v, u);
            f[u] += f[v] + sum[v];
            sum[u] += sum[v];
            dism[u] = max(dism[v], dism[u]);
        }
    };
    get_info(1, 0);
    vector<int> ans(n + 1);
    function<void(int, int)> dp = [&](int u, int fa)
    {
        int res = 0;
        int dm = 0, dmm = 0;
        for (auto v : adj[u])
        {
            if (v == fa)
                continue;
            res += f[v] + sum[v];
            if (dism[v] >= dm)
            {
                dmm = dm;
                dm = dism[v];
            }
            else if (dism[v] > dmm)
            {
                dmm = dism[v];
            }
            dp(v, u);
        }
        ans[u] = res;
        for (auto v : adj[u])
        {
            if (v == fa)
                continue;
            int tmp = res - sum[v];
            if (dm == dism[v])
            {
                tmp += sum[v] * (dmm - dis[u] + 1);
            }
            else
                tmp += sum[v] * (dm - dis[u] + 1);
            ans[u] = max(tmp, ans[u]);
        }
        for (auto v : adj[u])
        {
            if (v == fa)
                continue;
            ans[u] = max(ans[u], res - f[v] + ans[v]);
        }
    };
    dp(1, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
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