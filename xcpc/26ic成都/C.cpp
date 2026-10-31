#include <bits/stdc++.h>
#include <cassert>
#define int long long
using namespace std;

const int mod = 998244353, N = 100;
const int M = (N + 1) * N / 2;
vector cnt(N + 1, vector(N + 1, vector<int>(M + 1)));
void init()
{
    cnt[0][0][0] = 1;
    for (int l = 1; l <= N; l++)
    {
        cnt[l][0][0] = 1;
        for (int i = 1; i <= l; i++)
        {
            int mi = (i + 1) * i / 2, mx = i * (2 * l - i + 1) / 2;
            for (int s = mi; s <= mx; s++)
            {
                cnt[l][i][s] = (cnt[l - 1][i][s] + cnt[l - 1][i - 1][s - i]) % mod;
            }
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> a(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    if (m == 0)
    {
        int ans = 1;
        for (int i = 2; i <= n; i++)
        {
            (ans *= 2) %= mod;
        }
        cout << ans << '\n';
        return;
    }
    a[0] = {1, 0};
    for (int i = 1; i <= m; i++)
    {
        if (a[i][1] >= (a[i][0] - 1) * a[i][0] / 2)
        {
            cout << 0 << '\n';
            return;
        }
        if (a[i][1] < a[i - 1][1])
        {
            cout << 0 << '\n';
            return;
        }
    }
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        vector<int> ndp(n + 1);
        int d = a[i][0] - a[i - 1][0];
        int s = a[i][1] - a[i - 1][1];
        int l = max(0LL, (s - (d + 1) * d / 2) / d), r = min((s + d - 1) / d, n);
        for (int x = l; x <= r; x++)
        {
            if (s - d * x > M || s - d * x < 0)
                continue;
            for (int y = 0; y <= d && x + y <= a[i][0]; y++)
            {
                (ndp[x + y] += dp[x] * cnt[d][y][s - d * x] % mod) %= mod;
            }
        }
        dp.swap(ndp);
    }
    int res = 0;
    for (int i = 0; i <= n; i++)
        (res += dp[i]) %= mod;
    for (int i = a[m][0] + 1; i <= n; i++)
    {
        (res *= 2) %= mod;
    }
    cout << res << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}