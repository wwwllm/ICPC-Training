#include <bits/stdc++.h>
using namespace std;

// 二进制(倍增)优化dp
const int maxn = 1005;
int v[12 * maxn], w[10 * maxn], top;
int dp[12 * maxn];
signed main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int a, b, s;
        cin >> a >> b >> s;
        int k = 1;
        while (k <= s)
        {
            top++;
            v[top] = k * a;
            w[top] = k * b;
            s -= k;
            k *= 2;
        }
        if (s > 0)
        {
            top++;
            v[top] = s * a;
            w[top] = s * b;
        }
    }
    for (int i = 1; i <= top; i++)
        for (int j = m; j >= v[i]; j--)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    cout << dp[m] << endl;
    return 0;
}