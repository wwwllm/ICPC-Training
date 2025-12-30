#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2020/C
void solve()
{
    int b, c, d;
    cin >> b >> c >> d;
    bool ok = 1;
    int a = b ^ d;
    if ((a | b) - (a & c) == d)
        cout << a << '\n';
    else
        cout << -1 << '\n';
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