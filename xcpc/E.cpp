#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105481
void solve()
{
    int n, m;
    cin >> n >> m;
    if (n * m % 4 != 0 || (n == 2 && m == 2))
    {
        cout << "NO\n";
        return;
    }
    else
    {
        cout << "YES\n";
    }
    bool ok = 0;
    if (m > n)
    {
        swap(n, m);
        ok = 1;
    }
    vector M(n + 1, vector<int>(m + 1));
    int cur = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j + 3 <= m; j += 4)
        {
            M[i][j] = M[i][j + 1] = M[i][j + 2] = M[i][j + 3] = cur++;
        }
    }
    if (m % 4 == 2 && n % 4 == 2)
    {
        M[1][m] = M[1][m - 1] = M[2][m - 1] = M[3][m - 1] = cur++;
        M[2][m] = M[3][m] = M[4][m] = M[5][m] = cur++;
        M[4][m - 1] = M[5][m - 1] = M[6][m - 1] = M[6][m] = cur++;
        for (int i = 7; i + 3 <= n; i += 4)
        {
            for (auto j : {m, m - 1})
                M[i][j] = M[i + 1][j] = M[i + 2][j] = M[i + 3][j] = cur++;
        }
    }
    else
    {
        for (int i = 1; i + 3 <= n; i += 4)
        {
            for (int d = 0; d < m % 4; d++)
            {
                int j = m - d;
                M[i][j] = M[i + 1][j] = M[i + 2][j] = M[i + 3][j] = cur++;
            }
        }
    }
    auto T = [&]()
    {
        vector res(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                res[j][i] = M[i][j];
            }
        }
        M = res;
        swap(n, m);
    };
    if (ok)
    {
        T();
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << M[i][j] << ' ';
        }
        cout << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}