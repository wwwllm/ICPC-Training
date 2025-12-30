#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7, N = 1010;
int dp1[N], dp2[N][N];
signed main()
{
    int n, ans = 0;
    cin >> n;
    dp1[0] = 1; // 完全背包写法
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            dp1[j] = (dp1[j] + dp1[j - i]) % mod;
    cout << dp1[n] << endl;
    dp2[0][0] = 1; // 其他写法
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp2[i][j] = (dp2[i - 1][j - 1] + dp2[i - j][j]) % mod;
    for (int i = 1; i <= n; i++)
        ans = (dp2[n][i] + ans) % mod;
    cout << ans << endl;
    return 0;
}