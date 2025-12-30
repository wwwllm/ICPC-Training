#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1010;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll g[N][N], a[N], b[N];
ll dpl[N][2], dpr[N][2];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    memset(dpl, 0x3f, sizeof(dpl));
    memset(dpr, 0x3f, sizeof(dpr));
    dpl[1][0] = 0, dpl[1][1] = b[1];
    dpr[1][0] = 0, dpr[1][1] = a[1];
    for (int l = 2; l <= n; l++)
    {
        for (int x = 0; x < 2; x++)
            for (int y = 0; y < 2; y++)
            {
                bool flag = 0;
                for (int i = 1; i <= n; i++)
                    flag |= (g[i][l - 1] + y == g[i][l] + x);
                if (!flag)
                {
                    if (x == 0)
                        dpl[l][x] = min(dpl[l][x], dpl[l - 1][y]);
                    else
                        dpl[l][x] = min(dpl[l][x], dpl[l - 1][y] + b[l]);
                }
            }
    }
    for (int r = 2; r <= n; r++)
    {
        for (int x = 0; x < 2; x++)
            for (int y = 0; y < 2; y++)
            {
                bool flag = 0;
                for (int i = 1; i <= n; i++)
                    flag |= (g[r - 1][i] + y == g[r][i] + x);
                if (!flag)
                {
                    if (x == 0)
                        dpr[r][x] = min(dpr[r][x], dpr[r - 1][y]);
                    else
                        dpr[r][x] = min(dpr[r][x], dpr[r - 1][y] + a[r]);
                }
            }
    }
    ll ans = min(dpl[n][0], dpl[n][1]) + min(dpr[n][0], dpr[n][1]);
    if (ans < INF / 2)
        cout << ans << endl;
    else
        cout << -1 << endl;
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