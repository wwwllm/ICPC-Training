#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10, mod = 1e9 + 7;
vector<int> a;
int dp[N][2];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int ans = 0;
    for (int i = 0; i <= 32; i++)
    {
        int cnt1 = 0, cnt0 = 0;
        for (auto ele : a)
        {
            if ((ele >> i) & 1)
                cnt1++;
            else
                cnt0++;
        }
        dp[0][0] = 1, dp[0][1] = 0;
        for (int j = 1; j <= n; j++)
        {
            dp[j][0] = (dp[j - 1][1] * cnt1 % mod + dp[j - 1][0] * cnt0 % mod) % mod;
            dp[j][1] = (dp[j - 1][1] * cnt0 % mod + dp[j - 1][0] * cnt1 % mod) % mod;
        }
        ans = (ans + ((int)1 << i) * dp[n][1] % mod) % mod;
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}