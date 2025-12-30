#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/1990/B
void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> ans(n + 1);
    int op = 1;
    for (int i = y; i; i--)
    {
        ans[i] = op;
        op *= -1;
    }
    op = 1;
    for (int i = x; i <= n; i++)
    {
        ans[i] = op;
        op *= -1;
    }
    for (int i = y; i <= x; i++)
    {
        ans[i] = 1;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
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