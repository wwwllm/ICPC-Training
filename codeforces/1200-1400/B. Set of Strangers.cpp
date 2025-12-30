#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2069/B
unordered_map<int, int> mp;
void solve()
{
    mp.clear();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (auto &x : a)
        for (auto &y : x)
            cin >> y;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (mp[a[i][j]] == 0)
            {
                mp[a[i][j]] = 1;
            }
            else if (mp[a[i][j]] == 1)
            {
                if (i >= 1 && a[i - 1][j] == a[i][j])
                    mp[a[i][j]] = 2;
                if (j >= 1 && a[i][j - 1] == a[i][j])
                    mp[a[i][j]] = 2;
            }
        }
    int ans = 0, mx=0;
    for (auto [c, x] : mp)
    {
        ans += x;
        mx = max(mx, x);
    }
    cout << ans - mx << '\n';
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