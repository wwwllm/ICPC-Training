#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2000/E
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int w;
    cin >> w;
    vector<int> h(w);
    for (auto &x : h)
        cin >> x;
    sort(h.begin(), h.end(), greater<int>());
    int ans = 0;
    vector<vector<int>> g(n + 5, vector<int>(m + 5, 0)), pre(n + 5, vector<int>(m + 5, 0));
    for (int i = 1; i <= n - k + 1; i++)
        for (int j = 1; j <= m - k + 1; j++)
        {
            int x = min(n, i + k - 1), y = min(m, j + k - 1);
            g[i][j]++;
            g[x + 1][y + 1]++;
            g[i][y + 1]--;
            g[x + 1][j]--;
        }
    vector<int> res;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            pre[i][j] = g[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            res.push_back(pre[i][j]);
        }
    sort(res.begin(), res.end(), greater<int>());
    for (int i = 0; i < w; i++)
    {
        ans += res[i] * h[i];
    }
    cout << ans << '\n';
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