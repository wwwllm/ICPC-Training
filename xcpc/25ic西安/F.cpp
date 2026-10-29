#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n;
    cin >> n;
    vector<int> t(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<int> op(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int j = t[i];
        op[i] = a[j] > a[i];
    }
    vector adj(n + 1, vector<int>());
    for (int i = 1; i <= n; i++)
    {
        adj[i].push_back(t[i]);
    }
    vector<int> ans(n + 1, inf);
    auto dfs = [&](auto &&self, int u) -> void
    {
        if (ans[u] != inf)
            return;
        int v = t[u];
        if (op[u] ^ op[v])
        {
            if (ans[v] != inf)
            {
                ans[u] = max(abs(a[u] - a[v]), 2 * abs(a[u] - a[v]) - ans[v]);
            }
            else
            {
                int p = v;
                while (op[p] == op[v])
                    p = t[p];
                int l = min(a[u], a[v]), r = max(a[u], a[v]);
                if (a[p] > l && a[p] < r)
                {
                    self(self, v);
                    ans[u] = max(abs(a[u] - a[v]), 2 * abs(a[u] - a[v]) - ans[v]);
                }
                else
                {
                    ans[u] = abs(a[u] - a[v]);
                    self(self, v);
                }
            }
        }
        else
        {
            if (ans[v] == inf)
            {
                self(self, v);
            }
            ans[u] = ans[v] + 2 * abs(a[u] - a[v]);
        }
    };
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == inf)
            dfs(dfs, i);
        cout << ans[i] << " \n"[i == n];
    }
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}