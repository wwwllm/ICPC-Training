#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string A, B;
    cin >> A >> B;
    int n = A.size(), m = B.size();
    A = ' ' + A;
    B = ' ' + B;
    vector<int> a(n + 1), b(m + 1);
    a[0] = b[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        a[i] = A[i] - '0';
    }
    for (int i = 1; i <= m; i++)
    {
        b[i] = B[i] - '0';
    }
    vector<int> prea(n + 1), preb(m + 1);
    for (int i = 1; i <= n; i++)
    {
        prea[i] = a[i] + prea[i - 1];
        prea[i] %= 10;
    }
    for (int i = 1; i <= m; i++)
    {
        preb[i] = b[i] + preb[i - 1];
        preb[i] %= 10;
    }
    if (prea[n] != preb[m])
    {
        cout << "-1\n";
        return;
    }
    vector<array<int, 10>> nea(n + 1), neb(m + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (prea[i - 1] == j)
                nea[i][j] = i - 1;
            else
                nea[i][j] = nea[i - 1][j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (preb[i - 1] == j)
                neb[i][j] = i - 1;
            else
                neb[i][j] = neb[i - 1][j];
        }
    }
    vector dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                int vi = (prea[i] - k + 10) % 10;
                int vj = (preb[j] - k + 10) % 10;
                int posi = nea[i][vi];
                int posj = neb[j][vj];
                dp[i][j] = max(dp[i][j], dp[posi][posj] + 1);
            }
        }
    }
    cout << dp[n][m] << '\n';
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