#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105941
const int mod = 998244353, N = 5e3;
vector<int> invx(N + 1);
int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
int inv(int x)
{
    return exp(x, mod - 2);
}
void init()
{
    for (int i = 1; i <= N; i++)
    {
        invx[i] = inv(i);
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), siz(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != -1)
            siz[i] = siz[i - 1] + 1;
        else
            siz[i] = siz[i - 1] - 1;
    }
    vector<int> cnt(n + 1);
    vector dp(n + 1, vector<int>());
    vector<int> pre(n + 1, 1);
    dp[0].assign(1, 1);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != -1)
        {
            cnt[a[i]]++;
            continue;
        }
        vector ndp(n + 1, vector<int>());
        vector<int> npre(n + 1);
        for (int j = 0; j <= n; j++)
        {
            if (cnt[j] == 0)
                continue;
            ndp[j].assign(cnt[j] + 1, 0);
            if (j >= 1)
            {
                ndp[j][1] = pre[j - 1] * cnt[j] % mod * invx[siz[i] + 1] % mod;
                ndp[j][1] %= mod;
            }
            else
            {
                int tmp = dp[j].empty() ? 0 : dp[j][0];
                ndp[j][1] = tmp * cnt[j] % mod * invx[siz[i] + 1] % mod;
                ndp[j][1] %= mod;
            }
            npre[j] += ndp[j][1];
            npre[j] %= mod;
            for (int k = 2; k <= cnt[j]; k++)
            {
                if (dp[j].size() <= k - 1 || dp[j][k - 1] == 0)
                    continue;
                int p1 = (cnt[j] - k + 1) * invx[siz[i] + 1] % mod;
                ndp[j][k] += dp[j][k - 1] * p1 % mod;
                ndp[j][k] %= mod;
                npre[j] += ndp[j][k];
                npre[j] %= mod;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            npre[i] += npre[i - 1];
            npre[i] %= mod;
        }
        dp = ndp, pre = npre;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        for (auto p : dp[i])
        {
            ans += p;
            ans %= mod;
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    init();
    cin >> t;
    while (t--)
        solve();
    return 0;
}