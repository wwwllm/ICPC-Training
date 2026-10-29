#include <bits/stdc++.h>
#define int long long
using namespace std;

using i128 = __int128;

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
void solve()
{
    int n;
    cin >> n;
    vector adj(n + 1, vector<int>());
    vector<int> ind(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        ind[u]++, ind[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 1)
        {
            q.push(i);
            vis[i] = 1;
        }
    }
    int cnt = 0;
    while (q.size())
    {
        auto u = q.front();
        q.pop();
        cnt++;
        for (auto v : adj[u])
        {
            if (vis[v])
                continue;
            ind[v]--;
            if (ind[v] == 1)
            {
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    cout << (cnt + (n - cnt) * exp(2, mod - 2) % mod) % mod << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}