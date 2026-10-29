#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
using i128 = __int128_t;
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    i128 add = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        add += a[i] / x;
        a[i] %= x;
    }
    if (x == 1)
    {
        int ans = add % mod;
        cout << ans << '\n';
        return;
    }
    ranges::sort(a, greater<int>());
    for (int i = 0; i < n; i++)
    {
        if (add >= (x - 1) - a[i])
        {
            add -= (x - 1) - a[i];
            a[i] = 0;
        }
        else
        {
            a[i] += add;
            add = 0;
            break;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        (ans += a[i]) %= mod;
    }
    if (add != 0)
    {
        ans += add % (x - 1);
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
