#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2004/D
void solve()
{
    int n, q;
    cin >> n >> q;
    map<string, int> mp;
    mp["BG"] = 1, mp["BR"] = 2, mp["BY"] = 3, mp["GR"] = 4, mp["GY"] = 5, mp["RY"] = 6;
    vector<int> a(n + 1), pre(n + 1), suf(n + 2, n + 1);
    for (int i = 1; i <= n; i++)
    {
        string op;
        cin >> op;
        a[i] = mp[op];
    }
    vector<int> tmp(8, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            if (a[i] != j && a[i] + j != 7)
                pre[i] = max(pre[i], tmp[j]);
        }
        tmp[a[i]] = max(tmp[a[i]], i);
    }
    tmp.assign(8, n + 1);
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= 7; j++)
        {
            if (a[i] != j && a[i] + j != 7)
                suf[i] = min(tmp[j], suf[i]);
        }
        tmp[a[i]] = min(tmp[a[i]], i);
    }
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (a[x] + a[y] == 7)
        {
            if (pre[x] == 0 && suf[x] == n + 1)
                cout << "-1\n";
            else
            {
                int ans = 1e9;
                if (pre[x] != 0)
                    ans = min(ans, abs(x - pre[x]) + abs(pre[x] - y));
                if (suf[x] != n + 1)
                {
                    ans = min(ans, abs(x - suf[x]) + abs(suf[x] - y));
                }
                cout << ans << '\n';
            }
        }
        else
        {
            cout << abs(x - y) << '\n';
        }
    }
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