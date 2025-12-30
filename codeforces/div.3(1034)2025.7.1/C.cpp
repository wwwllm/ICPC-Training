#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 2), ans(n + 2), pre(n + 2), suf(n + 2);
    a[0] = 1e9, a[n + 1] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    pre[0] = a[0];
    suf[n + 1] = a[n + 1];
    for (int i = 1; i <= n; i++)
        pre[i] = min(pre[i - 1], a[i]);
    for (int i = n; i >= 1; i--)
        suf[i] = max(suf[i + 1], a[i]);
    for (int i = 1; i <= n; i++)
    {
        if (pre[i] == a[i] || suf[i] == a[i])
            ans[i] = 1;
        else
            ans[i] = 0;
    }
    for (int i = 1; i <= n; i++)
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