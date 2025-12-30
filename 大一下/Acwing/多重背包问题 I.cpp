#include <bits/stdc++.h>
using namespace std;

// dp[i][j]=max(dp[i-1][j],dp[i-1][j-1*v[i]]+w[i]*1……dp[i-1][j-k*v[i]]+k*w[i]);
// dp[i][j-v]=max(dp[i-1][j-v[i]],dp[i-1][j-k*v[i]]+(k-1)*w[i]);
// dp[i][j]=max(dp[i-1][j],dp[i][j-v]+w);
const int maxn = 1005;
int v[maxn], w[maxn], s[maxn];
int dp[maxn][maxn];
signed main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> s[i];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k * v[i] <= j && k <= s[i]; k++)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
    cout << dp[n][m] << endl;
    return 0;
}