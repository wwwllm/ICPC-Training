#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n);
    array<int, 3> dp = {0, 0, 0};
    for (int i = 0; i < n; i++)
    {
        int res = 1;
        for (int j = 0; j < 3; j++)
        {
            if (s[i] - 'a' == j)
                continue;
            (res += dp[j]) %= mod;
        }
        (dp[s[i] - 'a'] += res) %= mod;
    }
    cout << (dp[0] + dp[1] + dp[2]) % mod << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}