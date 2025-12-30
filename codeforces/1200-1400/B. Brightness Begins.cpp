#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2020/B
typedef long long ll;
void solve()
{
    ll k;
    cin >> k;
    ll n = k + (ll)(sqrt(k) + 0.5) ;
    cout << n << '\n';
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