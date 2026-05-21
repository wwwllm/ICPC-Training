#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 300, mod = 1e9 + 7;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if (c == '?')
            a[i] = -1, cnt++;
        else
            a[i] = c - 'a';
    }
    vector dp(3, vector(n + 1, vector<int>(n + 1)));
    if (a[1] == -1)
    {
        dp[0][1][0] = dp[1][0][1] = dp[2][0][0] = 1;
    }
    else
    {
        dp[a[1]][0][0] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        vector ndp(3, vector(n + 1, vector<int>(n + 1)));
        if (a[i] != -1)
        {
            for (int j = 0; j < 3; j++)
            {
                if (a[i] == j)
                    continue;
                for (int x = 0; x <= n; x++)
                {
                    for (int y = 0; y <= n; y++)
                    {
                        if (dp[j][x][y] == 0)
                            continue;
                        (ndp[a[i]][x][y] += dp[j][x][y]) %= mod;
                    }
                }
            }
        }
        else
        {
            for (int j = 0; j < 3; j++)
            {
                for (int x = 0; x <= n; x++)
                {
                    for (int y = 0; y <= n; y++)
                    {
                        if (dp[j][x][y] == 0)
                            continue;
                        for (int k = 0; k < 3; k++)
                        {
                            if (k == j)
                                continue;
                            int nx = x + (k == 0), ny = y + (k == 1);
                            (ndp[k][nx][ny] += dp[j][x][y]) %= mod;
                        }
                    }
                }
            }
        }
        dp = ndp;
    }
    vector f(N + 1, vector(N + 1, vector<int>(N + 1)));
    for (int i = 0; i < 3; i++)
    {
        for (int x = 0; x <= n; x++)
        {
            for (int y = 0; y <= n; y++)
            {
                int z = cnt - x - y;
                if (z < 0 || z > n)
                    continue;
                f[x][y][z] += dp[i][x][y];
            }
        }
    }
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            for (int k = 0; k <= N; k++)
            {
                if (i > 0)
                    f[i][j][k] = (f[i][j][k] + f[i - 1][j][k]) % mod;
                if (j > 0)
                    f[i][j][k] = (f[i][j][k] + f[i][j - 1][k]) % mod;
                if (k > 0)
                    f[i][j][k] = (f[i][j][k] + f[i][j][k - 1]) % mod;
                if (i > 0 && j > 0)
                    f[i][j][k] = (f[i][j][k] - f[i - 1][j - 1][k] + mod) % mod;
                if (i > 0 && k > 0)
                    f[i][j][k] = (f[i][j][k] - f[i - 1][j][k - 1] + mod) % mod;
                if (j > 0 && k > 0)
                    f[i][j][k] = (f[i][j][k] - f[i][j - 1][k - 1] + mod) % mod;
                if (i > 0 && j > 0 && k > 0)
                    f[i][j][k] = (f[i][j][k] + f[i - 1][j - 1][k - 1]) % mod;
            }
        }
    }
    while (q--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        cout << f[x][y][z] << '\n';
    }
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