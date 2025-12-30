#include <bits/stdc++.h>
#define ll long long
using namespace std;

// https://codeforces.com/problemset/problem/2044/E
void solve()
{
    int k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    ll p = 1;
    ll ans = 0;
    while (p < 1e10)
    {
        int l = (l2 + p - 1) / p;
        int r = (r2 / p);
        l = max(l1, l);
        r = min(r1, r);
        ans += max(0, r - l + 1);
        p *= k;
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