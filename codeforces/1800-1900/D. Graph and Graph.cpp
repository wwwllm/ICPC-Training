#include <bits/stdc++.h>
#define pb push_back
using namespace std;

// https://codeforces.com/problemset/problem/2059/D
const int INF = 0x3f3f3f3f;
void solve()
{
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vector<vector<int>> g1(n + 1), g2(n + 1);
    set<array<int, 2>> e;
    vector<int> point;
    int m1;
    cin >> m1;
    for (int i = 1; i <= m1; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        e.insert({u, v});
        g1[u].pb(v);
        g1[v].pb(u);
    }
    int m2;
    cin >> m2;
    for (int i = 1; i <= m2; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        if (e.find({u, v}) != e.end())
            point.pb(u), point.pb(v);
        g2[u].pb(v);
        g2[v].pb(u);
    }

    //dij
    vector<vector<int>> d(n + 1, vector<int>(n + 1, INF)), st(n + 1, vector<int>(n + 1, 0));
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> h;
    h.push({0, s1, s2});
    while (h.size())
    {
        auto [dtop, u, v] = h.top();
        h.pop();
        if (st[u][v])
            continue;
        st[u][v] = 1;
        for (auto uson : g1[u])
        {
            for (auto vson : g2[v])
            {
                if (dtop + abs(uson - vson) < d[uson][vson])
                {
                    d[uson][vson] = dtop + abs(uson - vson);
                    h.push({d[uson][vson], uson, vson});
                }
            }
        }
    }
    int ans = INF;
    for (auto p : point)
    {
        ans = min(d[p][p], ans);
    }
    if (ans < INF / 2)
        cout << ans << '\n';
    else
        cout << -1 << '\n';
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