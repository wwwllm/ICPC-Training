#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int p, m;
    cin >> p >> m;
    int t = (p - 1) ^ m;
    if (m == 0)
    {
        if (p == 2)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
        return;
    }
    int cur = 0;
    int ans = 0;
    for (int i = 60; i >= 0; i--)
    {
        cur += ((t >> i) & 1) << i;
        if ((m >> i) & 1)
        {
            int l = 0, r = (1LL << i) - 1;
            l += cur ^ (1LL << i), r += cur ^ (1LL << i);
            l--;
            int cl = l <= 0 ? 0 : ((l - 1) / p + 1);
            int cr = r <= 0 ? 0 : ((r - 1) / p + 1);
            ans += cr - cl;
        }
    }
    ans += t % p == 1;
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