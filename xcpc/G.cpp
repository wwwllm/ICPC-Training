#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105891
const int inf = 1e9;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int mi = inf, ma = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mi = min(mi, a[i]);
        ma = max(ma, a[i]);
    }
    int ans = 4;
    if (a[0] == mi || a[n - 1] == mi)
        ans--;
    if (a[0] == ma || a[n - 1] == ma)
        ans--;
    cout << min(ans, n) << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}