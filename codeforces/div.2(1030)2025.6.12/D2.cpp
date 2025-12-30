#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> p(n), d(n);
    for (auto &x : p)
        cin >> x;
    for (auto &x : d)
        cin >> x;
    vector<int> nxt(n * 2, -1);
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int v = (d[i] + p[i] % k + k) % k;
        if (m.count(v))
            nxt[i] = n+m[v];
        m[v] = i;
    }
    m.clear();
    for (int i = n - 1; i >= 0; i--)
    {
        int v = (d[i] - p[i] % k + k) % k;
        if (m.count(v))
            nxt[i + n] = m[v];
        m[v] = i;
    }
    vector<vector<int>> g(n * 2);
    queue<int> q;
    vector<int> out(n * 2);
    for (int i = 0; i < 2 * n; i++)
    {
        if (nxt[i] == -1)
            out[i] = 1, q.push(i);
        else
            g[nxt[i]].push_back(i);
    }

    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            out[v] = 1;
            q.push(v);
        }
    }

    int t;
    cin >> t;
    map<int, vector<array<int, 2>>> vis;
    for (int i = 0; i < n; i++)
    {
        int v = (p[i] - d[i] + k) % k;
        vis[v].push_back({p[i], i});
    }
    while (t--)
    {
        int a;
        cin >> a;
        if (!vis.count(a % k))
        {
            cout << "YES\n";
            continue;
        }

        auto &b = vis[a % k];
        auto it = lower_bound(b.begin(), b.end(), array<int, 2>({a, 0}));
        if (it == b.end())
        {
            cout << "YES\n";
            continue;
        }
        auto i = *it;
        if (out[i[1]])
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
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