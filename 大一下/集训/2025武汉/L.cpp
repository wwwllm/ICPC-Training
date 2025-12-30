#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            int u = 2 * a[i] - a[j];
            int pos = upper_bound(a.begin() + 1, a.end(), u) - a.begin() - 1;
            if (a[pos] == u)
            {
                int res = min(i - j, pos - i);
                res = res * 2 + 1;
                if (pos - i > i - j)
                    res++;
                ans = max(ans, res);
            }
        }
    } /*23558911*/
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