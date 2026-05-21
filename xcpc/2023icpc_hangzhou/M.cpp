#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int mid = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i > 1 && i < n && a[i] < a[i - 1] && a[i] < a[i + 1])
            mid = i;
    }
    long double ans = (long double)sum / (long double)n;
    int r = 0, l = 0;
    for (int i = 1; i <= mid + 1; i++)
    {
        l += a[i];
    }
    ans = max(ans, (long double)l / (long double)(mid + 1));
    for (int i = mid - 1; i <= n; i++)
    {
        r += a[i];
    }
    ans = max(ans, (long double)r / (long double)(n - mid + 2));
    cout << fixed << setprecision(18) << ans << '\n';
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