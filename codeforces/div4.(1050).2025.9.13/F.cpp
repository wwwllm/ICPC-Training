#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int len = 0;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        len = max(k, len);
        for (int j = 0; j < k; j++)
        {
            int p;
            cin >> p;
            g[i].push_back(p);
        }
    }
    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(i);
    int idx = 0;
    vector<int> ans(len);
    while (idx != len)
    {
        int mi = 1e9;
        bool ok = 1;
        for (auto i : s)
        {
            if (idx >= g[i].size())
            {
                s.clear();
                for (int i = 1; i <= n; i++)
                {
                    if (g[i].size() > idx)
                        s.insert(i);
                }
                ok = 0;
                break;
            }
            else
                mi = min(g[i][idx], mi);
        }
        if (!ok)
            continue;
        auto tmp = s;
        for (auto i : s)
        {
            if (g[i][idx] != mi)
                tmp.erase(i);
        }
        s = tmp;
        if (s.size() == 1)
        {
            auto i = *s.begin();
            while (idx < g[i].size())
                ans[idx] = g[i][idx], idx++;
            s.clear();
            for (int i = 1; i <= n; i++)
            {
                if (g[i].size() > idx)
                    s.insert(i);
            }
            continue;
        }
        else
            ans[idx++] = mi;
    }
    for (int i = 0; i < len; i++)
        cout << ans[i] << ' ';
    cout << '\n';
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