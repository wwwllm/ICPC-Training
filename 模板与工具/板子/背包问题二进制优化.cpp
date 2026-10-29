#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n, W;
    cin >> n >> W;
    vector<array<int, 3>> its(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> its[i][0] >> its[i][1] >> its[i][2];
    }
    vector<int> dp(W + 1);
    for (int i = 1; i <= n; i++)
    {
        auto [val, cost, cnt] = its[i];
        for (int k = 1; k <= cnt; k *= 2)
        {
            for (int i = W; i >= k * cost; i--)
                dp[i] = max(dp[i], dp[i - k * cost] + val * k);
            cnt -= k;
        }
        int k = cnt;
        for (int i = W; i >= k * cost; i--)
            dp[i] = max(dp[i - k * cost] + val * k, dp[i]);
    }
    cout << dp[W] << '\n';
    return 0;
}