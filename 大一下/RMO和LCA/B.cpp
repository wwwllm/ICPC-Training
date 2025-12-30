#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://ac.nowcoder.com/acm/contest/27836/B
const int mod = 1e9 + 7, N = 310;
int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> inv(N + 1), f(N + 1);
    inv[0]=f[0]=inv[1] = f[1] = 1;
    for (int i = 2; i <= N; i++)
        inv[i] = (exp(i, mod - 2) * inv[i - 1]) % mod;
    for (int i = 2; i < N; i++)
        f[i] = (f[i - 1] * i) % mod;
    auto C = [&](int n, int k) -> int
    {
        return f[n] * inv[k] % mod * inv[n - k] % mod;
    };
    auto A = [&](int n, int k) -> int
    {
        return f[n] * inv[n - k] % mod;
    };

    int ans = 0;
    for(int i=1;i<=min(n,k);i++){
        ans = (ans + C(n - 1, i - 1) * A(k, i)%mod) % mod;
    }
    cout << ans << '\n';
    return 0;
}