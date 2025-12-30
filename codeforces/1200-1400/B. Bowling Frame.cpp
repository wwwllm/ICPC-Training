#include <bits/stdc++.h>
#define ll long long
using namespace std;

// https://codeforces.com/problemset/problem/2041/B
void solve()
{
    ll a, b;
    cin >> a >> b;
    ll sum = a + b;
    ll l = 0, r = 1e9;
    while (l + 1 != r)
    {
        ll mid = l + r >> 1;
        if (mid * (mid + 1) / 2 <= sum)
            l = mid;
        else
            r = mid;
    }
    cout << l << '\n';
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