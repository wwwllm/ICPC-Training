#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(a.begin() + 1, a.end(), greater<int>());
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + b[i];
    }
    int p = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        while (p <= n && sum[p] <= i)
        {
            p++;
        }
        ans = max(ans, (p - 1) * a[i]);
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