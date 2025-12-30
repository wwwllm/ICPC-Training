#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> f(35);
void init()
{
    f[0] = 0, f[1] = 1;
    for (int i = 2; i < 35; i++)
        f[i] = f[i - 1] + f[i - 2] + 1;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> l(n + 1), r(n + 1), fa(n + 1), deg(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(32, 1e18));
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
        if (l[i])
            fa[l[i]] = i, deg[i]++;
        if (r[i])
            fa[r[i]] = i, deg[i]++;
        if (l[i] == 0 && r[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int i = q.front();
        deg[fa[i]]--;
        q.pop();
        for (int h = 0; h < 32; h++)
        {
            if (h == 0)
            {
                int lcnt = 0, rcnt = 0;
                if (l[i])
                    lcnt = dp[l[i]][0];
                if (r[i])
                    rcnt = dp[r[i]][0];
                dp[i][h] = lcnt + rcnt + 1;
            }
            else if (h == 1)
            {
                dp[i][h] = dp[i][h - 1] - 1;
            }
            else
            {
                int lcnt1 = 0, rcnt1 = 0;
                int lcnt2 = 0, rcnt2 = 0;
                if (l[i])
                {
                    lcnt1 = dp[l[i]][h - 1];
                    lcnt2 = dp[l[i]][h - 2];
                }
                else
                {
                    lcnt2 = f[h - 2];
                    lcnt1 = f[h - 1];
                }
                if (r[i])
                {
                    rcnt1 = dp[r[i]][h - 2];
                    rcnt2 = dp[r[i]][h - 1];
                }
                else
                {
                    rcnt2 = f[h - 1];
                    rcnt1 = f[h - 2];
                }
                dp[i][h] = min({rcnt1 + lcnt1, rcnt2 + lcnt2, lcnt1 + rcnt2});
            }
        }
        if (deg[fa[i]] == 0 && fa[i])
            q.push(fa[i]);
    }
    int ans = 1e18;
    for (int h = 0; h < 32; h++)
        ans = min(dp[1][h], ans);
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}