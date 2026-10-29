#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 0; i < 30; i++)
    {
        int u = (1LL << i);
        int cnt = min(n / u, k);
        if (cnt == 0)
            break;
        ans += cnt;
        n -= u * cnt;
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