#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, m;
int dp[N];
vector<int> v[N], w[N];
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int s;
        cin >> s;
        for (int j = 1; j <= s; j++)
        {
            int a, b;
            cin >> a >> b;
            v[i].push_back(a);
            w[i].push_back(b);
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 0; j--)
            for (int k = 0; k < v[i].size(); k++)
                if (v[i][k] <= j)
                    dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k]);
    cout << dp[m] << endl;
    return 0;
}