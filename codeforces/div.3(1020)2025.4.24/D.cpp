#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f, N = 2e5 + 10;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    int ans = INF;
    vector<int> pre(m + 2), suf(m + 2);
    pre[0] = 0;
    for (int i = 1, j = 1; i <= m; i++)
    {
        while (j <= n && a[j] < b[i])
            j++;
        pre[i] = j++;
    }
    suf[m + 1] = n + 1;
    for (int i = m, j = n; i >= 1; i--)
    {
        while (j >= 1 && a[j] < b[i])
            j--;
        suf[i] = j--;
    }
    if (pre[m] <= n)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i <= m; i++)
    {
        if (pre[i - 1] < suf[i + 1])
            ans = min(ans, b[i]);
    }
    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;
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