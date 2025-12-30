#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2056/B
//根据邻接矩阵可以得到i和j的大小关系，直接用可以排序
void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> g(n + 1, vector<char>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    sort(p.begin() + 1, p.end(), [&](int a, int b)
         { return (g[a][b] - '0' ? a < b : a > b); });
    for (int i = 1; i <= n; i++)
        cout << p[i] << ' ';
    cout << '\n';
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