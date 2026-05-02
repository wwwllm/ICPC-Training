#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int inf = 1e18;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    a.pb(k);
    int ans = -inf;
    for (int i = 0; i <= n; i++)
    {
        ans = max(ans, a[i] + a[(i + 1) % (n + 1)]);
    }
    cout << ans << '\n';
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