#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18, mod = 998244353;
void solve()
{
    int n, x;
    cin >> n >> x;
    x--;
    int a = (x >= 3) ? (x - 3) / 4 + 1 : 0;
    int b = (n >= 3) ? (n - 3) / 4 + 1 : 0;
    a++, b++;
    b -= a;
    int ans = (a % mod) * (b % mod) % mod;
    a = (x >= 1) ? (x - 1) / 4 + 1 : 0;
    b = (n >= 1) ? (n - 1) / 4 + 1 : 0;
    b -= a;
    (ans += (a % mod) * (b % mod) % mod) %= mod;
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