#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> t(n + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], t[a[i]] |= 1;
    vector<int> d;
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= a[i + 1])
            d.push_back(i);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += t[i];
    }
    vector<array<int, 2>> q;
    int pre = 1;
    int ans = 0;
    for (auto r : d)
    {
        q.push_back({pre, r});
        ans = max(ans, r - pre + 1);
        pre = r + 1;
    }
    q.push_back({pre, n});
    ans = max(ans, n - pre + 1);
    auto check = [&](int l, int r, int v)
    {
        for (int i = l, j = l + 1; i <= r; i++)
        {
            if (a[i] == v)
                continue;
            ans = max(ans, 1);
            int pre = a[i];
            if (j <= i)
                j = i + 1;
            while (j <= r && (a[j] == v || a[j] > pre))
            {
                if (a[j] != v)
                {
                    pre = a[j];
                    ans = max(ans, j - i + 1);
                }
                j++;
            }
            i = j - 1;
        }
    };
    if (cnt <= 2)
    {
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (t[i])
            {
                check(1, n, i);
            }
        }
        cout << ans << '\n';
        return;
    }
    vector g(n + 1, vector<int>());
    for (int i = 0; i < d.size(); i++)
    {
        int pos = d[i];
        int u = a[pos], v = a[pos + 1];
        if (u == v)
            g[u].push_back(i);
        else
            g[v].push_back(i), g[u].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (g[i].empty())
            continue;
        int m = g[i].size();
        for (int j = 0, k = 1; j < m;)
        {
            if (j >= k)
                k = j + 1;
            while (k < m && g[i][k] - g[i][k - 1] == 1)
                k++;
            int lpos = g[i][j], rpos = g[i][k - 1];
            int l = q[lpos][0], r = q[rpos + 1][1];
            // cerr << i << ' ' << l << ' ' << r << '\n';
            check(l, r, i);
            j = k;
        }
    }
    cout << ans << '\n';
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