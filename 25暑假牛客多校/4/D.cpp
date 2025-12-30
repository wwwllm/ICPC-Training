#include <bits/stdc++.h>
using namespace std;

const int N = 32;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(N * 4, vector<int>(N * 4));
    for (int i = 1; i < 4 * N; i++)
    {
        g[i][i] = 1;
        g[i][i - 1] = 1;
    }
    for (int i = 0; i < N; i++)
    {
        g[i * 4 + 3][i * 4] = 1;
    }
    for (int i = 0; i < N; i++)
    {
        if ((n >> i) & 1)
            g[0][i * 4] = 1;
    }
    cout << N * 4 << '\n';
    for (auto a : g)
    {
        for (auto x : a)
            cout << x << ' ';
        cout << '\n';
    }
    cout << '\n';
    return 0;
}