
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, t, k;
    cin >> n >> t >> k;
    int ans1 = (n-k)/t;
    cout << min(ans1, k + 1) << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}