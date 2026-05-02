#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i], cnt[a[i]]++;
    for (int i = 0; i < n; i++)
        cin >> b[i], cnt[b[i]]++;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] % 2 != 0)
        {
            cout << -1 << '\n';
            return;
        }
    }
    vector adj(n + 1, vector<int>{});
    vector<array<int, 4>> e;
    for (int i = 0; i < n; i++)
    {
        e.pb({a[i], b[i], i + 1, 0});
        adj[a[i]].pb(i);
        adj[b[i]].pb(i);
    }
    vector<int> ans;
    function<void(int)> dfs = [&](int u)
    {
        while (adj[u].size())
        {
            int idx = adj[u].back();
            adj[u].pop_back();
            if (e[idx][3])
                continue;
            e[idx][3] = 1;
            int v = (e[idx][0] == u) ? e[idx][1] : e[idx][0];
            if (e[idx][0] != u)
            {
                ans.pb(e[idx][2]);
            }
            dfs(v);
        }
    };
    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size())
            dfs(i);
    }
    cout << ans.size() << "\n";
    for (auto idx : ans)
        cout << idx << ' ';
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