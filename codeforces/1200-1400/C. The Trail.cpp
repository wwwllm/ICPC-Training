#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2055/C
void solve()
{
    int n, m;
    cin >> n >> m;
    string S;
    cin >> S;
    int x = 0, y = 0;
    vector<vector<int>> g(n, vector<int>(m, 0));
    for (auto &it : g)
        for (auto &ele : it)
            cin >> ele;
    vector<int> col(m), row(n);
    for (int i = 0; i < m; i++)
    {
        int res = 0;
        for (int j = 0; j < n; j++)
        {
            res += g[j][i];
        }
        col[i] = res;
    }
    for (int i = 0; i < n; i++)
    {
        int res = 0;
        for (int j = 0; j < m; j++)
        {
            res += g[i][j];
        }
        row[i] = res;
    }
    int k = 0;
    for (auto it : S)
    {
        if (it == 'D')
        {
            g[x][y] = k - row[x];
            row[x] = k;
            col[y] += g[x][y];
            x++;
        }
        else
        {
            g[x][y] = k - col[y];
            col[y] = k;
            row[x] += g[x][y];
            y++;
        }
    }
    g[x][y] = k - row[x];
    for (auto it : g)
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