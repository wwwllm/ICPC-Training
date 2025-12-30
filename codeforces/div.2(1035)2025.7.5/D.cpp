#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, mod;
    cin >> n >> mod;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = n; i >= 1; i--)//[1,i]中
    {
        for (int j = n - i; j >= 0; j--)//移除j个
            dp[j + 1] = (dp[j + 1] + dp[j] * (n - i + 1 - j) % mod * i % mod) % mod;
    }
    int sum = 0;
    for (auto res : dp)
        sum = (sum + res) % mod;
    cout << sum << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
};