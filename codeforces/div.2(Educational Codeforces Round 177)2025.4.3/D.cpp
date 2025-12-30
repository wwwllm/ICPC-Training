#include <bits/stdc++.h>
#define int long long
using namespace std;

// 每一种字符只能出现在奇数或者偶数位，且每一种取法的方案数相同
// 用dp求出取法数
const int mod = 998244353, N = 5e5 + 10;
int p[N], inp[N];
int ex_power(int a, int b);
void init()
{
    inp[0] = p[0] = 1;
    for (int i = 1; i < N; i++)
    {
        p[i] = p[i - 1] * i % mod;
        inp[i] = ex_power(p[i], mod - 2);
    }
}
int ex_power(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}
int f(vector<int> &a, int sum)
{
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (auto x : a)
    {
        if (x == 0)
            continue;
        for (int v = sum; v >= x; v--)
        {
            dp[v] = (dp[v] + dp[v - x]) % mod;
        }
    }
    return dp[sum];
}
void solve()
{
    vector<int> cnt(26);
    int n = 0;
    for (auto &x : cnt)
        cin >> x, n += x;
    int n0 = n / 2;
    int n1 = n - n0;
    int ans = p[n0] % mod * p[n1] % mod;
    for (auto x : cnt)
    {
        ans = (ans * inp[x]) % mod;
    }
    int res = f(cnt, n0);
    cout << ans * res % mod << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}