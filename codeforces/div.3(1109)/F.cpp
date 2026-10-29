#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector adj(n + 1, vector<int>());
    vector<int> outd(n + 1), st(n + 1, 1);
    vector<array<int, 2>> d(n + 1);
    vector<int> fa(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int f;
        cin >> f;
        fa[i] = f;
        adj[f].push_back(i);
        outd[f]++;
    }
    vector<int> val(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
        if (val[i])
            d[i] = {val[i], val[i]};
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (outd[i] == 0)
            q.push(i);
    }
    while (q.size())
    {
        auto u = q.front();
        q.pop();
        vector<array<int, 2>> tmp;
        int mi = n + 1, pos = -1;
        int s = 0;
        if (adj[u].size())
            s = adj[u].size();
        for (int i = 0; i < s; i++)
        {
            auto v = adj[u][i];
            if (d[v][0] < mi && d[v][0] != 0)
            {
                mi = d[v][0], pos = i;
            }
        }
        int ll = val[u] == 0 ? mi : val[u];
        int rr = ll;
        int pre = val[u];
        bool ok = 1;
        for (int k = 0; k < s; k++)
        {
            int i = (pos + k) % s;
            auto [l, r] = d[adj[u][i]];
            if (l == 0)
                continue;
            if (pre == 0 || pre + 1 == l)
            {
                pre = r;
                rr = r;
            }
            else
                ok = 0;
        }
        if (!ok)
        {
            cout << "NO\n";
            return;
        }
        d[u] = {ll, rr};
        outd[fa[u]]--;
        if (outd[fa[u]] == 0)
            q.push(fa[u]);
    }
    cout << "YES\n";
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