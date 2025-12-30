#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 1, j = 1; i <= n; i++)
    {
        int res = (i - 1) * a[i];
        j = i;
        while (j <= n && a[j] == a[i])
            j++;
        res += (n + 1 - j) * a[i];
        i = j - 1;
        ans = min(ans, res);
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