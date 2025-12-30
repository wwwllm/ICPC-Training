#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    int ma = 0, sum = 0;
    for (int i = 1; i <= n;i++){
        int k;
        cin >> k;
        ma = max(ma, k);
        sum += k;
    }
    cout << max(ma, (sum + x - 1) / x) << '\n';
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