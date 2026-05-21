#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353, N = 2e5;
vector<int> p(N + 1), ivp(N + 1), p2(N + 1);
inline int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
inline int inv(int x)
{
    return exp(x, mod - 2);
}
void init()
{
    p2[0] = p[0] = ivp[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        p[i] = p[i - 1] * i % mod;
    }
    ivp[N] = inv(p[N]);
    for (int i = N - 1; i >= 1; i--)
    {
        ivp[i] = ivp[i + 1] * (i + 1) % mod;
    }
    for (int i = 1; i <= N; i++)
    {
        p2[i] = p2[i - 1] * 2 % mod;
    }
}
inline int C(int n, int m)
{
    if (m > n || n < 0 || m < 0)
        return 0;
    return p[n] * ivp[n - m] % mod * ivp[m] % mod;
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<int, int> mp;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'x')
            continue;
        int j = i;
        while (j < n && s[j] == '.')
            j++;
        len += j - i;
        mp[j - i]++;
        i = j - 1;
    }
    unordered_map<int, int> dp;
    auto calc = [&](int x, int k) -> int
    {
        if (x < 0)
            return 0LL;
        if (dp.find(x) != dp.end())
            return dp[x];
        int m = x / (k + 2);
        int res = 0;
        for (int i = 0, p = 1; i <= m; i++, p = mod - p)
        {
            (res += p * C(x - i * (k + 1), i) % mod * p2[x - i * (k + 2)] % mod) %= mod;
        }
        return res;
    };
    vector<int> sum(n + 1, 0);
    sum[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int ans = exp(2, len);
        dp.clear();
        for (auto [x, c] : mp)
        {
            if (x > i)
                ans = ans * exp((calc(x, i) - calc(x - i - 1, i) + mod) % mod, c) % mod, ans = ans * exp(p2[x * c % (mod - 2)], mod - 2) % mod;
        }
        sum[i] = ans;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << (sum[i] - sum[i - 1] + mod) % mod << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}