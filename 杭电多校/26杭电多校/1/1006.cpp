#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5, mod = 998244353;
vector<int> p(N + 1), ivp(N + 1);
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
void init()
{
    ivp[0] = p[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        p[i] = p[i - 1] * i % mod;
    }

    ivp[N] = exp(p[N], mod - 2);
    for (int i = N - 1; i >= 1; i--)
    {
        ivp[i] = ivp[i + 1] * (i + 1) % mod;
    }
}
void solve()
{
    // int n = 7;
    // vector<int> a{0, 1, 2, 3, 4, 5, 6, 7};
    // vector<int> p(n);
    // ranges::iota(p, 1);
    // vector<int> cnt(n + 1);
    // vector<int> vis(n + 1);
    // auto calc = [&]()
    // {
    //     int res = 0;
    //     vis.assign(n + 1, 0);
    //     for (int i = 0; i < n; i++)
    //     {
    //         int pos = p[i];
    //         vis[pos] = 1;
    //         int c = 0;
    //         for (int j = 1; j <= n;)
    //         {
    //             if (vis[j] == 1)
    //             {
    //                 int k = j;
    //                 while (k <= n && vis[k] == 1)
    //                     k++;
    //                 c++;
    //                 j = k;
    //             }
    //             else
    //                 j++;
    //         }
    //         res += a[pos] * c;
    //         cnt[pos] += c;
    //     }
    //     return res;
    // };
    // int ans = 0;
    // do
    // {
    //     ans += calc();
    // } while (next_permutation(p.begin(), p.end()));
    // cout << ans << '\n';
    // for (int i = 1; i <= n; i++)
    //     cout << cnt[i] << " \n"[i == n];
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        sum %= mod;
    }
    int ans = sum * (n + 3) % mod + a[0] + a[n - 1];
    ans %= mod;
    cout << ans * inv(6) % mod << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    // init();
    while (t--)
        solve();
    return 0;
}
