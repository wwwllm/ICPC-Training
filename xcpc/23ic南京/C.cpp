#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int m, p;
    cin >> p >> m;
    int l = max(0LL, m / p - 1), r = m / p + 1;
    int ans = l;
    for (int i = l; i <= r; i++)
    {

        if (((1 + i * p) ^ (p - 1)) <= m)
            ans++;
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