#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    array<int, 3> c = {0, 0, 0};
    cin >> n >> m;
    for (int i = 0; i < 3; i++)
        cin >> c[i];
    vector<int> idx(3);
    idx = {0, 1, 2};
    ranges::sort(idx, [&](int a, int b)
                 { return c[a] < c[b]; });

    vector<int> d(n + 2);
    vector<array<int, 2>> q(m);
    for (int i = 0; i < m; i++)
    {
        auto &[l, r] = q[i];
        cin >> l >> r;
        d[l]++, d[r + 1]--;
    }
    ranges::sort(q, [&](array<int, 2> &a, array<int, 2> &b)
                 { return a[1] - a[0] < b[1] - b[0]; });
    vector<int> ans(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        d[i] += d[i - 1];
        if (d[i] == 0)
        {
            for (auto j : {0, 1, 2})
            {
                int pos = idx[j];
                if (c[pos])
                {
                    c[pos]--;
                    ans[i] = pos;
                    break;
                }
            }
        }
    }
    for (auto [l, r] : q)
    {
        for (int i = l; i <= r; i++)
        {
            for (auto j : {0, 2, 1})
            {
                int pos = idx[j];
                if (c[pos])
                {
                    c[pos]--;
                    ans[i] = pos;
                    break;
                }
            }
        }
        set<int> c;
        for (int i = l; i <= r; i++)
        {
            c.insert(ans[i]);
        }
        if (c.size() > 2)
        {
            cout << -1 << '\n';
            return;
        }
    }
    string s = "RGB";
    for (int i = 1; i <= n; i++)
    {
        cout << s[ans[i]];
    }
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}