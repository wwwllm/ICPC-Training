#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<char> ans(n * 2 + 1, ' ');

    vector<array<int, 2>> a(m);
    for (auto &[l, r] : a)
        cin >> l >> r;
    sort(a.begin(), a.end(), [&](array<int, 2> a, array<int, 2> b)
         { return a[0] > b[0]; });

    int cnt = 0, ch = -1e9;
    for (int i = 0; i < m; i++)
    {
        if (ch >= a[i][0] && ch <= a[i][1])
            continue;
        else
        {
            cnt++;
            ch = a[i][0];
            ans[ch] = '(';
        }
    }
    if (cnt > n)
    {
        cout << -1 << '\n';
        return;
    }
    for (int i = 1, j = 1; i <= n - cnt; i++)
    {
        while (j <= 2 * n && ans[j] == '(')
            j++;
        if (j <= 2 * n)
            ans[j] = '(';
    }
    for (int i = 1; i <= n * 2; i++)
        if (ans[i] == ' ')
            ans[i] = ')';
    int op = 0;
    bool ok = 1;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (ans[i] == '(')
            op++;
        else
            op--;
        if (op < 0)
            ok = 0;
    }
    if (ok == 0)
    {
        cout << -1 << '\n';
        return;
    }
    for (int i = 1; i <= 2 * n; i++)
        cout << ans[i];
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