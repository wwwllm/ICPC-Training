#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] & 1)
            cnt1++;
        else
            cnt0++;
    }
    cout << cnt0 * cnt1 % mod << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}