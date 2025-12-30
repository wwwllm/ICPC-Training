#include <bits/stdc++.h>
using namespace std;

// dp[i][j]=f[i][j]+max(dp[i-1][j],dp[i-1][j-1])
const int N = 505, INF = 1e9;
int n;
int dp[N][N];
int ans = -INF;
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i + 1; j++)
            dp[i][j] = -INF;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> dp[i][j];
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = dp[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}