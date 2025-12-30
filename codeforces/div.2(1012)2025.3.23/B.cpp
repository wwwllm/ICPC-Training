#include <bits/stdc++.h>
using namespace std;

const int N = 60;
char a[N][N];
int g[N][N];
bool b[N][N];
void solve()
{
    int n, m;
    cin >> n >> m;
    memset(b, 0, sizeof b);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j], g[i][j] = a[i][j] - '0';
    bool flag = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (g[i][j])
                b[i][j] = 1;
            else
                break;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (g[j][i])
                b[j][i] = 1;
            else
                break;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (g[i][j] && !b[i][j])
                flag = 0;
    cout << (flag ? "YES" : "NO") << endl;
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