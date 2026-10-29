#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            (ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    int ans = exp(2, (n * (c - 1) + m * (r - 1) - (c - 1) * (r - 1)) % (mod - 1));
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