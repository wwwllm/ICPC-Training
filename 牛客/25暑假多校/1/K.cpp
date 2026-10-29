#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int du;
        cin >> du;
        int v;
        for (int j = 0; j < du; j++)
            cin >> v, g[i].push_back(v);
    }
    vector<int> ans(n + 1);
    auto f = [&](int u)
    {
        set<array<int, 2>> res;
        set<array<int, 2>> st;

        vector<int> tmp;
        int i = 0, p = u;
        while (1)
        {
            if (st.find({p, i}) != st.end())
                break;
            st.insert({p, i});
            if (i == 0)
                tmp.push_back(p);

            int x = g[p][i];
            for (int j = 0; j < g[x].size(); j++)
            {
                if (g[x][j] == p)
                {
                    i = (j + 1) % g[x].size();
                    break;
                }
            }
            res.insert({min(p, x), max(p, x)});
            p = x;
        }
        for (int x : tmp)
        {
            ans[x] = res.size();
        }
    };
    for (int i = 1; i <= n; i++)
    {
        if (!ans[i])
            f(i);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}