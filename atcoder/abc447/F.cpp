#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector adj(n + 1, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> cnt(n + 1);
    int ans = 0;
    function<void(int, int)> dfs = [&](int u, int f)
    {
        vector<int> tmp;
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            dfs(v, u);
            tmp.push_back(cnt[v]);
        }
        sort(tmp.begin(), tmp.end(), greater<int>());
        tmp.push_back(0), tmp.push_back(0);
        int son = adj[u].size();
        if (son >= 4)
        {
            ans = max(ans, tmp[0] + tmp[1] + 1);
            cnt[u] = tmp[0] + 1;
        }
        else if (son == 3)
        {
            ans = max(ans, tmp[0] + 1);
            cnt[u] = 1;
        }
        else if (son == 2)
        {
            ans = max(ans, 1LL);
            cnt[u] = 0;
        }
        else if (son == 1)
        {
            cnt[u] = 0;
        }
    };
    dfs(1, 0);
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