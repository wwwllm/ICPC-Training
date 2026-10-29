#include <bits/stdc++.h>
using namespace std;

void solve1()
{
    int n, s;
    cin >> n >> s;
    vector<int> val(n + 1);
    for (int i = 1; i <= n; i++)
    {
        val[i] = (s >> (i - 1) & 1);
    }
    auto get = [&](int &u, int &v)
    {
        cin >> u >> v;
    };
    for (int i = 1; i < n; i++)
    {
        int u, v;
        get(u, v);
        if ((val[u] ^ val[v]) && s != (1 << (n - 1)))
        {
            cout << max(u, v) << ' ' << min(u, v) << endl;
        }
        else
        {
            cout << min(u, v) << ' ' << max(u, v) << endl;
        }
    }
}
void solve2()
{
    int n;
    cin >> n;
    vector adj(n + 1, vector<array<int, 2>>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
        {
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 1});
        }
        else
        {
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 0});
        }
    }
    vector<int> val(n + 1, -1);
    val[n] = 0;
    auto dfs = [&](auto &&self, int u, int f) -> void
    {
        for (auto [v, w] : adj[u])
        {
            if (v == f || val[v] != -1)
                continue;
            val[v] = val[u] ^ w;
            self(self, v, u);
        }
    };
    dfs(dfs, n, -1);
    int s1 = 0, s2 = 0;
    for (int i = n; i >= 1; i--)
    {
        s1 = s1 * 2 + val[i];
        s2 = s2 * 2 + (!val[i]);
    }
    if (s1 == 0 || s2 == 0)
    {
        cout << (1 << (n - 1)) << endl;
        return;
    }
    if (s1 >= 1 && s1 <= (1 << (n - 1)))
    {
        cout << s1 << endl;
    }
    else
    {
        cout << s2 << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, q;
    cin >> t >> q;
    if (q == 1)
    {
        while (t--)
            solve1();
    }
    else
    {
        while (t--)
            solve2();
    }
    return 0;
}