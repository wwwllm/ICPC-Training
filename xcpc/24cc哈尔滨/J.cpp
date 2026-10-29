#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<array<int, 2>> X;
    vector g(n + 1, vector<int>());
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        int x, u;
        cin >> x >> u;
        u--;
        g[u].push_back(x);
        X.push_back({x, u});
    }

    for (int i = 0; i < n; i++)
    {
        g[i].push_back(inf);
        X.push_back({inf, i});
        ranges::sort(g[i], greater<>());
    }
    ranges::sort(X);

    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({g[i].back(), i});
        g[i].pop_back();
    }
    auto power = a;
    int cur = 0;
    m = X.size();
    for (int i = 0; i < m;)
    {
        auto [x, u] = X[i];
        while (pq.size() && cur != x)
        {
            auto [y, v] = pq.top();
            pq.pop();
            int d = min(a[v], x - cur);
            a[v] -= d;
            cur += d;
            if (a[v])
                pq.push({y, v});
        }
        if (cur != x)
        {
            break;
        }
        while (pq.size() && pq.top()[0] <= cur)
            pq.pop();
        int j = i;
        while (j < m && X[j][0] == x)
        {
            pq.push({g[X[j][1]].back(), X[j][1]});
            a[X[j][1]] = power[X[j][1]];
            g[X[j][1]].pop_back();
            j++;
        }
        i = j;
    }
    cout << cur << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}