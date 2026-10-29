#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    vector<int> val(n);
    vector<int> pre(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> ord(n);
    ranges::iota(ord, 0);
    int ans = 0;
    pre[0] = a[0];
    val[0] = 2 * d * a[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
        val[i] = 2 * d * a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int l = (i - d + n) % n, r = (i + d) % n;
        int sum = 0;
        if (l > r)
            sum = pre[r] + pre[n - 1] - (l == 0 ? 0 : pre[l - 1]);
        else
            sum = pre[r] - (l == 0 ? 0 : pre[l - 1]);
        sum -= a[i];
        // cerr << l << ' ' << r << '\n';
        val[i] -= sum;
        if (val[i] > 0)
            ans += val[i];
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