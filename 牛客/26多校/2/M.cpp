#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    if (m < n)
    {
        cout << (m - 1) * m / 2 << '\n';
    }
    else
    {
        cout << n * (n - 1) / 2 - m << '\n';
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