#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n, C;
    cin >> n >> C;
    int N = 1 << 9;
    vector<int> a(n + 2), X(n + 2), Y(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        X[i] = a[i] % N;
        Y[i] = a[i] / N;
    }
    vector<int> dp(n + 2, inf);
    dp[0] = 0;
    vector g(N, vector<int>(N, inf));
    for (int x = 0; x < N; x++)
    {
        g[Y[0]][x] = min(g[Y[0]][x], dp[0] - C + (X[0] ^ x));
    }
    for (int i = 1; i <= n + 1; i++)
    {
        for (int y = 0; y < N; y++)
        {
            dp[i] = min(dp[i], g[y][X[i]] + (Y[i] ^ y) * N);
        }
        for (int x = 0; x < N; x++)
        {
            g[Y[i]][x] = min(g[Y[i]][x], dp[i] - C + (X[i] ^ x));
        }
    }
    cout << dp[n + 1] + (n + 1) * C << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}