#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18, N = 1000;
vector<int> f(N + 1, inf);
void init()
{
    f[1] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i + i / j <= N)
                f[i + i / j] = min(f[i + i / j], f[i] + 1);
        }
    }
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    k = min(k, 15 * n);
    vector<int> dp(k + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = k; j >= f[a[i]]; j--)
        {
            dp[j] = max(dp[j], dp[j - f[a[i]]] + b[i]);
        }
    }
    cout << dp[k] << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    solve();
    return 0;
}