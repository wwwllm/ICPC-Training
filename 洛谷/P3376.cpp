#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 250, INF = 0x3f3f3f3f;
vector<array<int, 3>> g[N];
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int l, r, c;
        cin >> l >> r >> c;
        int li = g[l].size(), ri = g[r].size();
        g[l].push_back({r, c, ri});
        g[r].push_back({l, 0, li});
    }
    vector<int> pre(n + 1), d(n + 1), lst(n + 1);
    vector<bool> st(n + 1, 0);
    auto bfs = [&]() -> bool
    {
        st.assign(n + 1, 0);
        st[s] = 1;
        d[s] = INF;
        queue<int> q;
        q.push(s);
        while (q.size())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < g[u].size(); i++)
            {
                auto [ed, f, op] = g[u][i];
                if (st[ed] || f == 0)
                    continue;
                st[ed] = 1;
                d[ed] = min(d[u], f);
                lst[ed] = u;
                pre[ed] = i;
                if (ed == t)
                    return 1;
                q.push(ed);
            }
        }
        return 0;
    };
    int ans = 0;
    while (bfs())
    {
        ans += d[t];
        for (int i = t; i != s; i = lst[i])
        {
            g[lst[i]][pre[i]][1] -= d[t];
            g[i][g[lst[i]][pre[i]][2]][1] += d[t];
        }
    }
    cout << ans << endl;
}