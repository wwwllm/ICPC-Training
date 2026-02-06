#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    map<int, int> pre;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int p;
        if (pre.count(a[i]) == 0)
            p = 0;
        else
            p = pre[a[i]];
        ans += (n - i + 2) * (n - i + 1) / 2 * (i - p);
        pre[a[i]] = i;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}