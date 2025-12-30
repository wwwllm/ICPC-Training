#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/1989/B
void solve()
{
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int ans = 1e5;
    for (int len = 0; len < m; len++)
    {
        int j = len, i = 0, res = 0;
        for (; j < m; j++)
        {
            while (i < n && a[i] != b[j])
                i++;
            if (i == n)
                break;
            if (a[i] == b[j])
                res++, i++;
        }
        ans = min(m + n - res, ans);
    }
    cout << ans << '\n';
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