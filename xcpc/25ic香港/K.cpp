#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    a.resize(2 * n + 1);
    for (int i = 1; i <= n; i++)
    {
        a[i + n] = a[i];
    }
    vector<int> nxt(2 * n + 1);
    {
        vector<int> stk;
        for (int i = 2 * n; i >= 1; i--)
        {
            while (stk.size() && a[stk.back()] <= a[i])
                stk.pop_back();
            if (stk.size())
                nxt[i] = stk.back();
            else
                nxt[i] = 2 * n + 1;
            stk.push_back(i);
        }
    }
    vector<array<int, 2>> g(n);
    for (int i = 0; i < n; i++)
    {
        g[i] = {i + 1, i + 1};
    }
    auto cmp = [&](array<int, 2> &x, array<int, 2> &y)
    { return x[0] == y[0] ? x[1] > y[1] : x[0] < y[0]; };
    while (g.size() > 1)
    {
        array<int, 2> mi = {inf, inf};
        vector<array<int, 2>> ng;
        for (auto [pos, s] : g)
        {
            array<int, 2> tmp = {a[pos], nxt[pos] - pos};
            if (cmp(tmp, mi))
            {
                mi = tmp;
            }
        }
        for (auto [pos, s] : g)
        {
            array<int, 2> tmp = {a[pos], nxt[pos] - pos};
            if (tmp == mi && nxt[pos] - s <= n)
            {
                ng.push_back({nxt[pos], s});
            }
        }
        if (ng.empty())
            break;
        g = ng;
    }
    int pos = g[0][1];
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        b.push_back(a[i + pos]);
    }
    for (int i = 1; i < n; i++)
    {
        b[i] = max(b[i - 1], b[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " \n"[i == n - 1];
    }
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