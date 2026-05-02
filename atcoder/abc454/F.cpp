#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n / 2; i++)
    {
        cnt[i] = (a[n - i + 1] - a[i] + m) % m;
    }
    vector<int> d(n + 1);
    int sum = 0, ans = 0;
    for (int i = 1; i <= n / 2 + 1; i++)
    {
        d[i] = (cnt[i] - cnt[i - 1] + m) % m;
        sum += d[i];
    }
    ranges::sort(d, greater<int>());
    sum /= m;
    for (int i = 0; i < sum; i++)
        ans += m - d[i];
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