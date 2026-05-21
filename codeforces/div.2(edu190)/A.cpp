#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    cout << min({n * a,
                 (n / 3) * b + (n % 3) * a,
                 (n + 2) / 3 * b})
         << '\n';
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