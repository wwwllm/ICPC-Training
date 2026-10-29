#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353, G = 3, N = 5e5;
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
int inv(int x)
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
vector<int> Z(string &s)
{
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    for (int i = 1, j = 1; i < n; i++)
    {
        z[i] = max(0LL, min(j + z[j] - i, z[i - j]));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > j + z[j])
            j = i;
    }
    return z;
}
namespace NTT
{

    void dft(vector<int> &a)
    {
        int n = a.size();
        vector<int> rev(n);
        for (int i = 0; i < n; i++)
        {
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0);
        }
        for (int i = 0; i < n; i++)
        {
            if (i < rev[i])
                swap(a[i], a[rev[i]]);
        }
        for (int k = 1; k < n; k <<= 1)
        {
            int wn = exp(G, (mod - 1) / (2 * k));
            for (int i = 0; i < n; i += 2 * k)
            {
                int w = 1;
                for (int j = 0; j < k; j++)
                {
                    int u = a[i + j], v = a[i + j + k] * w % mod;
                    a[i + j] = (u + v) % mod;
                    a[i + j + k] = (u - v + mod) % mod;
                    (w *= wn) %= mod;
                }
            }
        }
    }
    void idft(vector<int> &a)
    {
        int n = a.size();
        reverse(a.begin() + 1, a.end());
        dft(a);
        int inv = exp(n, mod - 2);
        for (int i = 0; i < n; i++)
        {
            (a[i] *= inv) %= mod;
        }
    }
    vector<int> mul(vector<int> a, vector<int> b)
    {
        int tot = a.size() + b.size() - 1;
        int n = 1;
        while (n < tot)
        {
            n <<= 1;
        }
        a.resize(n), b.resize(n);
        dft(a), dft(b);
        for (int i = 0; i < n; i++)
        {
            (a[i] *= b[i]) %= mod;
        }
        idft(a);
        a.resize(tot);
        return a;
    }
};
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    auto get_f = [&](string &s) -> vector<int>
    {
        auto z = Z(s);
        int n = s.size();
        vector<int> f(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            int len = i + 1;
            int c = z[i + 1] / len + 1;
            for (int j = 1; j <= c; j++)
            {
                f[j * len]++;
            }
        }
        return f;
    };
    auto C = [&](int n, int m) -> int
    {
        if (m > n || n < 0 || m < 0)
            return 0LL;
        return p[n] * ivp[m] % mod * ivp[n - m] % mod;
    };
    auto f = get_f(s);
    ranges::reverse(s);
    auto g = get_f(s);
    f = NTT::mul(f, g);
    int ans = 0;
    if (k == 0)
    {
        cout << f[n] << '\n';
        return;
    }
    for (int i = 2; i <= n - k; i++)
    {
        int tmp = f[i] * C(n - i - 1, k - 1) % mod;
        (ans += tmp) %= mod;
    }
    cout << ans << '\n';
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