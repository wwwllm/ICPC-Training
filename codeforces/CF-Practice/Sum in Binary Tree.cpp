#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    while (n)
    {
        ans += n;
        n /= 2;
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}