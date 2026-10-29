#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> pre1(n + 1), pre2(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pre1[i] = pre1[i - 1] + (a[i] == 1 ? 1 : -1);
        pre2[i] = pre2[i - 1] + (a[i] == 3 ? -1 : 1);
    }
    int cur = 1e9;
    bool ok = 0;
    for (int i = 1; i < n; i++)
    {
        if (pre2[i] >= cur)
            ok = 1;
        if (pre1[i] >= 0)
            cur = min(cur, pre2[i]);
    }
    cout << (ok ? "YES\n" : "NO\n");
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