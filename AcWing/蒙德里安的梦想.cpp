#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 13, M = 1 << N;
int dp[N][M];
bool st[M];
int n, m;
signed main()
{
    while (cin >> n >> m, n || m)
    {
        for (int i = 0; i < 1 << n; i++)
        {
            st[i] = 1;
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if ((i >> j) & 1)
                {
                    if (cnt & 1)
                        st[i] = 0;
                    cnt = 0;
                }
                else
                    cnt++;
            }
            if (cnt & 1)
                st[i] = 0;
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < (1 << n); j++)
                for (int k = 0; k < (1 << n); k++)
                    if ((j & k) == 0 && st[j | k])
                        dp[i][j] += dp[i - 1][k];
        }
        cout << dp[m][0] << endl;
    }
    return 0;
}