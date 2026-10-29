#include <bits/stdc++.h>
#define ll long long
using namespace std;
using i128 = __int128;

const ll mod = 998244353;
ll epow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<ll, 2>> a(n);
    for (auto &[b, cnt] : a)
        cin >> cnt >> b;
    sort(a.begin(), a.end(), greater<array<ll, 2>>());
    ll cnt = 0, num = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!cnt)
        {
            ll res = (a[i][1] + m - 1) / m;
            ans = (ans + res % mod * epow(2, a[i][0]) % mod) % mod;
            ll p = a[i][1] % m;
            cnt = p == 0 ? 0 : (m - p);
            num = a[i][0];
        }
        else
        {
            if (num - a[i][0] > 62)
                break;
            i128 res = ((i128)cnt << (num - a[i][0])) - (i128)a[i][1];
            if (res > (i128)(1LL << 62))
                break;
            if (res <= 0)
            {
                a[i][1] -= (cnt << (num - a[i][0]));
                cnt = 0, num = 0;
                if (a[i][1] > 0)
                    i--;
            }
            else
            {
                cnt = (ll)res;
                num = a[i][0];
            }
        }
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