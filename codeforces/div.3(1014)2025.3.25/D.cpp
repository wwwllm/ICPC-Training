#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, kk;
    cin >> n >> m >> kk;
    int k = (n + kk - 1) / n;
    int cnt = m - k + 1;
    cout << (k+cnt-1)/ cnt << endl;
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