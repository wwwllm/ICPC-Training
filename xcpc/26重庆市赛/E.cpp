#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            (ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}
int inv(int x)
{
    return exp(x, mod - 2);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    int ans = 0;
    int sum = 1;
    for (int i = 1; i <= n; i++)
    {
        (sum *= (d[i] + 1) * (d[i] + 2) / 2 % mod) %= mod;
    }
    for (int c = 0; c <= n; c++)
    {
        vector<int> dp1(n + 1), dp2(n + 1);
        dp1[0] = 1, dp2[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            int A = 0, B = 0, C = 0, D = 0;
            int tot = (d[i] + 1) * (d[i] + 2) / 2 % mod;
            if (c >= 1 && c <= d[i]) 
                A = c * (d[i] - c + 1) % mod;
            if (c - 1 >= 0 && c - 1 <= d[i])
                B = c;
            if (c >= 0 && c <= d[i])
                C = (d[i] - c + 1) % mod;
            D = (tot - A - B - C + 3 * mod) % mod;
            for (int j = n; j >= 1; j--)
            {
                dp1[j] = (dp1[j] * (D + B) % mod + dp1[j - 1] * A % mod) % mod;
                dp2[j] = (dp2[j] * D % mod + dp2[j - 1] * (A + B) % mod) % mod;
            }
            (dp1[0] *= (D + B)) %= mod;
            (dp2[0] *= D) %= mod;
        }
        int c1 = 0, c2 = 0;
        for (int i = 0; i <= c; i++)
        {
            if (i != c)
            {
                (c2 += dp2[i]) %= mod;
            }
            (c1 += dp1[i]) %= mod;
        }
        (ans += (c1 - c2 + mod) % mod) %= mod;
    }
    (ans *= inv(sum)) %= mod;
    cout << ans << '\n';
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