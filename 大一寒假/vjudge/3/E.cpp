#include <bits/stdc++.h>
#define ll long long
using namespace std;

const __int128 maxn = 1e18;
set<__int128> mp;
void solve()
{
    ll n;
    cin >> n;
    if (mp.count(n))
        cout << "YES" << endl;
    else if (n > 1e6 + 1e12 + 1)
    {
        ll ans = (-1 + sqrt(4 * n - 3)) / 2;
        if (ans + 1 + ans * ans == n)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for (ll k = 2; k <= 1000000; k++)
    {
        __int128 sum = 1 + k, ki = k * k;
        while (sum + ki < maxn)
        {
            sum += ki;
            ki *= k;
            mp.insert(sum);
        }
    }
    while (t--)
        solve();
    return 0;
}
