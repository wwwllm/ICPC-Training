#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> q(n), d(n);
    for (auto &x : q)
        cin >> x;
    for (auto &x : d)
        cin >> x;
    int Q;
    cin >> Q;
    while (Q--)
    {
        int a;
        cin >> a;
        int r = lower_bound(q.begin(), q.end(), a) - q.begin();
        if (r == n)
        {
            cout << "YES\n";
            continue;
        }
        vector<vector<array<int, 2>>> vis(n, vector<array<int, 2>>(k));
        auto dfs = [&](auto &&self, int u, int t, int op) -> bool
        {
            if (vis[u][t][op])
                return 0;
            vis[u][t][op] = 1;
            if ((u == n - 1 && op == 1) || (u == 0 && op == 0))
                return 1;
            int v, tmp, time;
            if (op)
            {
                v = u + 1;
                time = t + q[v] - q[u];
            }
            else
            {
                v = u - 1;
                time = t + q[u] - q[v];
            }
            time %= k;
            if (time == d[v])
                tmp = !op;
            else
                tmp = op;
            return self(self, v, time, tmp);
        };
        int t = (q[r] - a) % k, tmp;
        if (t == d[r])
            tmp = 0;
        else
            tmp = 1;
        bool ans = dfs(dfs, r, t, tmp);
        cout << (ans ? "YES\n" : "NO\n");
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