#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// https://codeforces.com/problemset/problem/1981/B
void solve()
{
    ll n, m;
    cin >> n >> m;
    ll st = max(0LL, n - m), ed = n + m;
    ll ans = st | ((1LL << (__lg(st ^ ed) + 1)) - 1);
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