#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105423
const int mod = 998244353;
vector<int> kmp(string s)
{
    int n = s.size();
    vector<int> nxt(n + 1);
    for (int i = 1, j = 0; i < n; i++)
    {
        while (j && s[i] != s[j])
            j = nxt[j];
        j += (s[i] == s[j]);
        nxt[i + 1] = j;
    }
    return nxt;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int m = s.size();
    auto f = kmp(s);
    vector dp(vector(k + 1, vector<int>(m + 1)));
    dp[0][0] = 1;
    vector nxt(m + 1, vector<int>(26));
    nxt[0][s[0] - 'a'] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            char c = j + 'a';
            int p = i;
            while (p && s[p] != c)
                p = f[p];
            p += (s[p] == c);
            nxt[i][j] = p;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        vector ndp(k + 1, vector<int>(m + 1));
        for (int j = 0; j <= k; j++)
        {
            for (int p = 0; p < m; p++)
            {
                for (int x = 0; x < 26; x++)
                {
                    int pp = nxt[p][x], jj = j;
                    if (pp == m)
                    {
                        jj++;
                        pp = 0;
                    }
                    if (jj > k)
                        continue;
                    ndp[jj][pp] += dp[j][p];
                    ndp[jj][pp] %= mod;
                }
            }
        }
        dp = ndp;
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans += dp[k][i];
        ans %= mod;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}