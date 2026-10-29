#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353, N = 200;
vector<int> p(N + 1), ivp(N + 1);
int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans % a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
int inv(int x)
{
    return exp(x, mod - 2);
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    auto calc = [&]()
    {
        int res = 0;
        for (int st = 2; st <= n; st += 2)
        {
            vector dp(2 * n + 1, vector<int>(3 * n + 1));
            dp[n][st + n] = 1;
            for (int i = 1; i <= n; i++)
            {
                vector ndp(2 * n + 1, vector<int>(3 * n + 1));
                char d1 = s[i], d2 = s[i + n];
                vector<int> work1, work2;
                if (d1 == '?')
                    work1.push_back(1), work1.push_back(-1);
                else if (d1 == 'L')
                    work1.push_back(-1);
                else
                    work1.push_back(1);
                if (d2 == '?')
                    work2.push_back(1), work2.push_back(-1);
                else if (d2 == 'L')
                    work2.push_back(-1);
                else
                    work2.push_back(1);
                for (int d1 = 0; d1 <= 2 * n; d1++)
                {
                    for (int d2 = 0; d2 <= 3 * n; d2++)
                    {
                        for (auto w1 : work1)
                        {
                            for (auto w2 : work2)
                            {
                                int nx1 = d1 + w1, nx2 = d2 + w2;
                                if (nx1 >= 0 && nx1 <= 2 * n && nx2 >= 0 && nx2 <= 3 * n && nx2 > nx1)
                                    ndp[nx1][nx2] += dp[d1][d2], ndp[nx1][nx2] %= mod;
                            }
                        }
                    }
                }
                dp = ndp;
            }
            for (int x = st + n + 1; x <= 3 * n; x++)
            {
                res += dp[st + n][x];
                res %= mod;
            }
        }
        return res;
    };
    int ans = calc();
    for (int i = 1; i <= 2 * n; i++)
    {
        if (s[i] == 'L')
            s[i] = 'R';
        else if (s[i] == 'R')
            s[i] = 'L';
    }
    ans += calc();
    ans %= mod;
    cout << ans << '\n';
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