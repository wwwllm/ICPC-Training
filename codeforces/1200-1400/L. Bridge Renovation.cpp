#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2038/L
void solve()
{
    int n;
    cin >> n;
    int cnt = (2 * n) / 3;
    int k = (2 * n % 3);
    int ans = (k + n + 1) / 2 + cnt;
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