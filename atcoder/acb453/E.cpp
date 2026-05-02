#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353, N = 2e5;
vector<int> p(N + 1), ivp(N + 1);
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
void init()
{
    p[0] = ivp[0] = 1;
    for (int i = 1; i <= N; i++)
        p[i] = p[i - 1] * i % mod;
    ivp[N] = inv(p[N]);
    for (int i = N - 1; i >= 1; i--)
    {
        ivp[i] = ivp[i + 1] * (i + 1) % mod;
    }
}
void solve()
{
    int n;
    cin >> n;
    auto C = [&](int n, int m) -> int
    {
        if (m > n || n < 0)
            return 0;
        return p[n] * ivp[m] % mod * ivp[n - m] % mod;
    };
    vector<int> pre1(n + 2), pre2(n + 2), pre3(n + 2);
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        int x = n - r, y = n - l;
        int ll = max(x, l), rr = min(r, y);
        pre1[l]++, pre1[r + 1]--;
        pre2[x]++, pre2[y + 1]--;
        if (ll <= rr)
            pre3[ll]++, pre3[rr + 1]--;
    }
    for (int i = 1; i <= n; i++)
    {
        pre1[i] += pre1[i - 1], pre2[i] += pre2[i - 1], pre3[i] += pre3[i - 1];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int a = pre1[i] - pre3[i], b = pre2[i] - pre3[i], c = pre3[i];
        if (a + b + c < n || a > i)
            continue;
        ans += C(c, i - a);
        ans %= mod;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}