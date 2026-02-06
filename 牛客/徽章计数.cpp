#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 2e5;
const int mod = 1e9 + 7;
vector<int> p(N + 1), ivp(N + 1);
int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
void init()
{
    p[0] = ivp[0] = 1;
    for (int i = 1; i <= N; i++)
        p[i] = p[i - 1] * i % mod;
    ivp[N] = exp(p[N], mod - 2);
    for (int i = N - 1; i >= 1; i--)
        ivp[i] = ivp[i + 1] * (i + 1) % mod;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    unordered_map<int, int> mp;
    for (auto x : a)
        mp[x]++;
    auto C = [&](int x, int y) -> int
    {
        if (y < 0 || y > x)
            return 0;
        if (y == 0 || y == x)
            return 1;
        if (y > x - y)
            y = x - y;
        int res = 1;
        for (int i = 1; i <= y; ++i)
        {
            res = res * (x - i + 1) % mod * exp(i, mod - 2) % mod;
        }

        return res;
    };
    int cnt = 0;
    int ans = 1;
    bool ok = 1;
    for (auto [x, c] : mp)
    {
        if (c % x != 0 || c < x)
            ok = 0;
        else
        {
            cnt += c / x;
            ans = ans * p[c] % mod * exp(ivp[x], c / x) % mod * ivp[c / x] % mod;
        }
    }
    if (cnt > m)
        ok = 0;
    ans = ans * C(m, cnt) % mod * p[cnt] % mod;
    if (ok)
        cout << ans << '\n';
    else
        cout << 0 << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}