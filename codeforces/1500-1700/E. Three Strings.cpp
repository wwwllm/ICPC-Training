#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string a, b, c;
    cin >> a >> b >> c;
    int n = c.size();
    int lena = a.size(), lenb = b.size();
    vector<vector<int>> dp(lena + 1, vector<int>(lenb + 1));
    for (int i = 1; i <=lena; i++)
    {
        dp[i][0] = dp[i - 1][0] + (c[i - 1] != a[i - 1]);
    }
    for (int i = 1; i <= lenb; i++)
    {
        dp[0][i] = dp[0][i - 1] + (c[i - 1] != b[i - 1]);
    }
    for (int i = 1; i <= lena; i++)
    {
        for (int j = 1; j <= lenb; j++)
        {
            dp[i][j] = min(dp[i][j - 1] + (c[i + j - 1] != b[j - 1]), dp[i - 1][j] + (c[i + j - 1] != a[i - 1]));
        }
    }
    cout << dp[lena][lenb] << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}