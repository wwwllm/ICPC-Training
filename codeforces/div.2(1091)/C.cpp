#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (gcd(n, a) == 1 && gcd(m, b) == 1 && gcd(n, m) <= 2)
        cout << "YES\n";
    else
        cout << "NO\n";
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