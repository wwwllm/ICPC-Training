#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    array<int, 2> dp{0, 0};
    for (int i = 1; i <= n; i++)
    {
        array<int, 2> ndp{inf, inf};
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                ndp[j] = min(ndp[j], dp[k] + max(k == 0 ? a[i - 1] : 0, j == 1 ? a[i + 1] : 0));
            }
        }
        dp = ndp;
    }
    cout << min(dp[0], dp[1]) << '\n';
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