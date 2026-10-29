#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k, c;
    cin >> n >> k >> c;
    vector<int> a(n);
    int cost = 0;
    for (auto &x : a)
        cin >> x, x -= cost, cost += c;
    sort(a.begin(), a.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < k; i++)
        ans += a[i] + c * i;
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}