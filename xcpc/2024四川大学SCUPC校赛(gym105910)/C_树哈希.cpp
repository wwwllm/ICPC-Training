#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105910
const int mod = 998244353, B = 233, N = 1e6;
vector<int> p(N + 1), pre(N + 1);
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
void init()
{
    p[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        p[i] = p[i - 1] * i % mod;
    }
    pre[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        pre[i] = B * pre[i - 1] % mod + 1;
        pre[i] %= mod;
    }
}
void solve()
{
    int n;
    cin >> n;
    cout << pre[n - 1] * p[n - 1] % mod << '\n';
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