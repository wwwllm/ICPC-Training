#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i] %= k;
    ranges::sort(a);
    int ans = 1e9;
    for (int i = 0; i < n - 1; i++)
    {
        ans = min(a[i] + k - a[(i + 1) % n], ans);
    }
    ans = min(a[n - 1] - a[0], ans);
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}