#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 1));
    queue<array<int, 2>> S;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            S.push({i, j});
    for (int i = 0; i < n; i += 2)
    {
        for (int j = 0; j < n; j++)
        {
            if (S.size())
            {
                auto [x, y] = S.front();
                S.pop();
                a[i][j] = x, a[i + 1][j] = y;
            }
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
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}