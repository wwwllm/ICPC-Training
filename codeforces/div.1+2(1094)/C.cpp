#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    auto tmp = a;
    ranges::sort(tmp);
    int mid = tmp[(n + 1) / 2];
    vector<int> dp(n + 1, -inf);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int cntl = 0, c = 0;
        for (int j = i; j >= 1; j--)
        {
            if (a[j] < mid)
                cntl++;
            else if (a[j] == mid)
                c++;
            int len = i - j + 1;
            if (!(len & 1))
                continue;
            len = (len + 1) / 2;
            if (cntl < len && (cntl + c) >= len)
            {
                dp[i] = max(dp[i], dp[j - 1] + 1);
            }
        }
    }
    cout << dp[n] << '\n';
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