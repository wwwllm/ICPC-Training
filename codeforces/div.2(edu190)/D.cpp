#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<int> nxta(n + 2, n), nxtb(n + 2, n);
    vector<int> dp(n + 1, n);
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        nxta[a[i]] = i, nxtb[b[i]] = i;
        if (a[i] == b[i])
        {
            int pa = nxta[a[i] + 1], pb = nxtb[a[i] + 1];
            if (pa == pb)
            {
                dp[i] = dp[pa];
            }
            else
                dp[i] = min(pa, pb);
        }
        int pa = nxta[1], pb = nxtb[1];
        if (pa == pb)
            ans += dp[pa] - i;
        else
            ans += min(pa, pb) - i;
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