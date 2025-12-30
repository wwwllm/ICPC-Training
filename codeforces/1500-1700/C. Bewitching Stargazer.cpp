#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2052/F
void solve()
{
    int n, k;
    cin >> n >> k;
    int cnt = 1, res = 0, ans = 0;
    while (n >= k)
    {
        if (n & 1)
            ans += cnt * (n + 1) / 2 + n * (cnt - 1) * cnt / 2 + res * cnt / 2, res += cnt;
        cnt <<= 1;
        n >>= 1;
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