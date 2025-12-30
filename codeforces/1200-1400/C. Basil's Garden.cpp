#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// https://codeforces.com/problemset/problem/1987/C
void solve()
{
    int n;
    cin >> n;
    ll ans = 0;
    vector<ll> h(n);
    for (auto &x : h)
        cin >> x;
    for (int i = n - 1; i >= 0; i--)
        ans = max(ans + 1, h[i]);
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