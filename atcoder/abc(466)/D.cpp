#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> op(m);
    for (int i = 0; i < m; i++)
        cin >> op[i][0] >> op[i][1];
    vector<int> row(n + 1), col(n + 1);
    int ans = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        auto [x, y] = op[i];
        if (row[x] == 0 && col[y] == 0)
            ans++;
        row[x] |= 1, col[y] |= 1;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}