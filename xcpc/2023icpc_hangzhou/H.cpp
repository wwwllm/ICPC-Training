#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7, N = 5e5, inf = 1e9;
vector<int> p(N + 1), ivp(N + 1);
inline int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
inline int inv(int x)
{
    return exp(x, mod - 2);
}
inline void init()
{
    p[0] = ivp[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        p[i] = p[i - 1] * i % mod;
    }
    ivp[N] = inv(p[N]);
    for (int i = N - 1; i >= 1; i--)
    {
        ivp[i] = ivp[i + 1] * (i + 1) % mod;
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), w(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i], b[i]--;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    vector adj(n, vector<int>());
    for (int i = 0; i < n; i++)
    {
        adj[b[i]].push_back(i);
    }
    vector<int> p(n, -1);
    for (int i = 0; i < n; i++)
    {
        int j = b[i];
        if (a[i] >= a[j] + w[j] || i == j)
            p[i] = 0;
        else if (a[i] < a[j])
            p[i] = 1;
    }
    vector<array<int, 2>> dis(n, {inf, inf});
    queue<int> q;
    vector<int> ind(n);
    for (int i = 0; i < n; i++)
    {
        for (auto v : adj[i])
            ind[v]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (p[i] != -1)
            q.push(i), ind[i] = 0, dis[i][p[i]] = 0;
    }
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (p[v] != -1 || ind[v] == 0)
                continue;
            ind[v]--;
            for (int i = 0; i < 2; i++)
            {
                dis[v][i] = min(dis[v][i], dis[u][i] + 1);
            }
            if (ind[v] == 0)
                q.push(v);
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        if (p[i] != -1)
        {
            ans[i] = a[i] + (p[i] == 1 ? w[i] : 0);
            ans[i] %= mod;
        }
        else
        {
            if ((dis[i][0] > dis[i][1] && dis[i][0] != inf) || dis[i][1] == inf)
            {
                ans[i] = a[i] % mod;
            }
            else
            {
                int p1 = ivp[dis[i][1] + 1];
                ans[i] = p1 * (a[i] + w[i]) % mod + (1 - p1 + mod) % mod * a[i] % mod;
                ans[i] %= mod;
            }
        }
        cout << ans[i] << " \n"[i == n - 1];
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    init();
    cin >> t;
    while (t--)
        solve();
    return 0;
}