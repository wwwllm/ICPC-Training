#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 10;
ll a[N];
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    ll res = a[1];
    ll ans = 0;
    for (int i = 2; i <= n; i++)
        if (a[i] % res == 0)
            ans = gcd(ans, a[i]);
    if (res == ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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