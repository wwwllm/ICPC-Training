#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 998244353;
ll exp(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    ll n;
    cin >> n;
    if ((n - 4) % 6 != 0 || n < 4)
    {
        cout << 0 << '\n';
        return;
    }
    else
    {
        cout << 2 << '\n';
    }
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