#include <bits/stdc++.h>
using namespace std;

// dp[i,j]
// 0:dp[i-1][j-1]
// 1:dp[i-1][j]+1
// 2:dp[i][j-1]+1
// 3:dp[i-1][j-1]+1
const int N = 1005;
int n, m;
char a[N], b[N];
int dp[N][N];
signed main()
{
    cin >> n >> a + 1;
    cin >> m >> b + 1;
    for (int i = 1; i <= n; i++)
        dp[i][0] = i;
    for (int i = 1; i <= m; i++)
        dp[0][i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            if (a[i] == b[j])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    cout << dp[n][m] << endl;
    return 0;
}