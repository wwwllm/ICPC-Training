#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = ' ' + s + ' ', t = ' ' + t + ' ';
    int ans1 = 0, ans2 = 0;
    auto calc = [&]()
    {
        vector lcp(n + 2, vector<int>(n + 2));
        for (int i = n; i >= 1; i--)
        {
            for (int j = n; j >= 1; j--)
            {
                if (s[i] == s[j])
                    lcp[i][j] = lcp[i + 1][j + 1] + 1;
            }
        }
        vector<int> pre(m + 1);
        for (int r = 1; r <= n; r++)
        {
            vector<int> T(n + 2);
            vector<int> cur(m + 1);
            for (int j = 1; j <= m; j++)
            {
                if (s[r] == t[j])
                {
                    cur[j] = pre[j - 1] + 1;
                    ans2 += cur[j];
                }
            }
            for (int j = 1; j <= m; j++)
            {
                T[0]++;
                T[cur[j] + 1]--;
            }
            for (int i = 1; i <= n; i++)
                T[i] += T[i - 1];
            for (int i = 1; i <= n; i++)
                T[i] += T[i - 1];
            for (int l = 1; l < r; l++)
            {
                int k = r - l + 1;
                int lmi = max(1LL, k - lcp[l][r + 1]);
                int lma = r - l;
                ans1 += T[lma] - T[lmi - 1];
            }
            pre = cur;
        }
    };
    calc();
    swap(s, t);
    swap(n, m);
    calc();
    cout << ans1 + ans2 / 2 << '\n';
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