#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int mod = 1e9 + 7;
int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
int inv(int x)
{
    return exp(x, mod - 2);
}
struct Number
{
    int z = 0;
    int p = 1;
    Number(int x)
    {
        mul(x);
    }
    void mul(int x)
    {
        x %= mod;
        if (x == 0)
            z++;
        else
            p = p * x % mod;
    }
    void div(int x)
    {
        x %= mod;
        if (x==0)
            z--;
        else
            p = p * inv(x) % mod;
    }
    int get()
    {
        if (z)
            return 0;
        else
            return p;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), val(n + 1);
    int root;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        val[a[i]] = i;
        if (!a[i])
            root = i;
    }
    vector adj(n + 1, vector<int>{});
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> dp(n + 1), fa(n + 1);
    function<void(int, int)> get_cnt = [&](int u, int f)
    {
        dp[u] = 1;
        fa[u] = f;
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            get_cnt(v, u);
            dp[u] = dp[u] * (dp[v] + 1) % mod;
        }
    };
    get_cnt(root, 0);
    vector<int> vis(n + 1);
    int ans(dp[root]);
    Number cur(dp[root]);
    vis[val[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        int u = val[i];
        while (!vis[u])
        {
            vis[u] = 1;
            cur.div(dp[u] + 1);
            cur.mul(dp[u]);
            u = fa[u];
        }
        ans = (ans + cur.get()) % mod;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // >> t;
    while (t--)
        solve();
    return 0;
}