#include <bits/stdc++.h>
using namespace std;

int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    int p = n * n - 1;
    int x = 0, y = 0, idx = 0;
    auto cmp = [&](int x, int y) -> bool
    {
        return x >= 0 && x < n && y >= 0 && y < n && !a[x][y];
    };
    while (p)
    {
        a[x][y] = p--;
        int dx = x + d[idx][0], dy = y + d[idx][1];
        if (cmp(dx, dy))
        {
            x = dx, y = dy;
        }
        else
        {
            idx = (idx + 1) % 4;
            x += d[idx][0], y += d[idx][1];
        }
    }
    for (auto it : a)
    {
        for (auto ele : it)
            cout << ele << ' ';
        cout << '\n';
    }
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