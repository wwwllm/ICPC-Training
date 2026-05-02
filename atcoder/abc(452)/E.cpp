#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    vector<int> pre1(n + 1), prei(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pre1[i] = (pre1[i - 1] + a[i]) % mod;
        prei[i] = (prei[i - 1] + a[i] * i % mod) % mod;
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int res = prei[n];
        int tmp = 0;
        for (int k = 1; k * i <= n; k++)
        {
            int l = k * i, r = min((k + 1) * i - 1, n);
            tmp += (pre1[r] - pre1[max(0LL, l - 1)]) * k % mod * i % mod;
        }
        ans += (res - tmp + mod) % mod * b[i] % mod;
        ans %= mod;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}