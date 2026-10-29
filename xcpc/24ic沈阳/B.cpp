#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    if (gcd(n, m) == 1)
    {
        cout << "Yes\n";
        for (int i = 0; i < n; i++)
        {
            cout << (i * m + 1) % (n * m) << " \n"[i == n - 1];
        }
        for (int i = 0; i < m; i++)
        {
            cout << (i * n + 1) % (n * m) << " \n"[i == m - 1];
        }
    }
    else
    {
        cout << "No\n";
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}