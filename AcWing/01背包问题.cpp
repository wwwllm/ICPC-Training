#include <bits/stdc++.h>
using namespace std;

// dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
const int maxn = 1005;
int n, v;
int dp[maxn];
int V[maxn], w[maxn];
signed main()
{
    cin >> n >> v;
    for (int i = 1; i <= n; i++)
        cin >> V[i] >> w[i];
    for (int i = 1; i <= n; i++)
        for (int j = v; j >=V[i]; j--)
                dp[j] = max(dp[j], dp[j - V[i]] + w[i]);
    cout << dp[v] << endl;
    return 0;
}