#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9, mod = 998244353;
void solve()
{
    int n;
    cin >> n;
    int sum1 = 0, sum0 = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (__builtin_popcount(x) & 1)
            sum1 += x;
        else
            sum0 += x;
    }
    cout << max(sum0, sum1) << '\n';
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