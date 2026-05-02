#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353, N = 2e5;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> c(k);
    vector adj(n + 1, vector<int>());
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < k; i++)
    {
        cin >> c[i];
    }
    if (n == 2)
    {
        for (int i = 0; i < k; i++)
            if (c[i] > 1)
            {
                cout << i + 1 << ' ' << i + 1 << '\n';
                return;
            }
        cout << -1 << '\n';
        return;
    }
    vector<int> leaf;
    auto dfs = [&](auto &&self, int u, int f) -> void
    {
        if (adj[u].size() == 1 && adj[u][0] == f)
            leaf.push_back(u);
        for (auto v : adj[u])
        {
            if (v == f)
                continue;
            self(self, v, u);
        }
    };
    int root;
    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() > 1)
        {
            dfs(dfs, i, 0);
            root = i;
            break;
        }
    }
    vector<int> p;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        if (c[i] >= 2)
        {
            p.push_back(i);
            sum += c[i];
            if (sum >= leaf.size())
                break;
        }
    }
    if (sum < leaf.size())
    {
        cout << -1 << '\n';
        return;
    }
    vector<int> ans(n + 1, -1);
    int cur = 0;
    for (int i = 0; i < leaf.size(); i++)
    {
        while (c[p[cur]] == 0)
        {
            (cur += 1) %= p.size();
        }
        ans[leaf[i]] = p[cur];
        c[p[cur]]--;
        (cur += 1) %= p.size();
    }
    if (c[p[cur]])
    {
        ans[root] = p[cur];
        c[p[cur]]--;
    }
    cur = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == -1)
        {
            while (cur < k && c[cur] == 0)
                cur++;
            ans[i] = cur;
            c[cur]--;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] + 1 << " \n"[i == n];
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