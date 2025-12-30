#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    if (n % p == 0)
    {
        int cnt = n / p;
        if (cnt * q == m)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else
        cout << "YES\n";
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