#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 10;
ll a[N];
ll pre[N];
void solve()
{
    int n, k;
    ll x;
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    ll res = x % pre[n], cnt = x / pre[n];
    if (res == 0)
    {
        if (cnt > k)
            cout << 0 << endl;
        else
            cout << (k - cnt) * n + 1 << endl;
    }
    else
    {
        int pos;
        ll sum = 0;
        for (pos = n; pos >= 1; pos--)
        {
            sum += a[pos];
            if (sum >= res)
                break;
        }
        if (cnt >= k)
            cout << 0 << endl;
        else
        {
            ll ans = (k - cnt - 1) * n + pos;
            cout << ans << endl;
        }
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