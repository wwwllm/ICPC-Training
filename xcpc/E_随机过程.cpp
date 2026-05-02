#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://qoj.ac/contest/2530
const int mod = 998244353, N = 1e3;
int exp(int a, int b)
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
int inv(int x)
{
    return exp(x, mod - 2);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    int cnt = 1;
    int cur = 26;
    for (int i = 1; i <= m; i++)
    {
        cnt += min(cur, n);
        cnt %= mod;
        cur = cur * 26;
        if (cur >= n)
            cur = n;
    }
    cur = 26;
    int e = 1;
    for (int i = 1; i <= m; i++)
    {
        e += cur * (1 - exp((1 - inv(cur) + mod) % mod, n) + mod) % mod;
        e %= mod;
        cur = cur * 26 % mod;
    }
    cout << cnt << ' ' << e << '\n';
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