#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9, N = 5e3, mod = 998244353;
vector<int> p(N + 1), ivp(N + 1);
inline int exp(int a, int b)
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
inline int inv(int x)
{
    return exp(x, mod - 2);
}
void init()
{
    p[0] = ivp[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        p[i] = p[i - 1] * i % mod;
    }
    ivp[N] = inv(p[N]);
    for (int i = N - 1; i >= 1; i--)
    {
        ivp[i] = ivp[i + 1] * (i + 1) % mod;
    }
}
inline int C(int n, int m)
{
    if (m > n || n < 0)
        return 0;
    return p[n] * ivp[m] % mod * ivp[n - m] % mod;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int cnt = ranges::count(a, -1);
    vector<int> L(n + 1, n), R(n + 2, n);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != -1)
            L[i] = min(L[i - 1], a[i]);
        else
            L[i] = L[i - 1];
    }
    for (int i = n; i >= 1; i--)
    {
        if (a[i] != -1)
            R[i] = min(R[i + 1], a[i]);
        else
            R[i] = R[i + 1];
    }
    vector<int> T(n + 1);
    for (int i = 1; i <= n; i++)
        if (a[i] != -1)
            T[a[i]] = 1;
    vector<int> pre(n + 1);
    pre[0] = !T[0];
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + !T[i];
    }
    vector sum(n + 1, vector<int>(n + 1));
    for (int c = 0; c <= cnt; c++)
    {
        for (int x = 1; x <= n; x++)
        {
            int tmp = 0;
            if (c >= pre[x - 1])
                tmp = C(c, pre[x - 1]) * p[cnt - pre[x - 1]] % mod * p[pre[x - 1]] % mod;
            sum[c][x] = (sum[c][x - 1] + tmp) % mod;
        }
    }
    vector<int> prec(n + 1);
    for (int i = 1; i <= n; i++)
    {
        prec[i] = prec[i - 1] + (a[i] == -1);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ma = min(L[l - 1], R[r + 1]);
        int c = prec[r] - prec[l - 1];
        cout << sum[c][ma] << '\n';
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