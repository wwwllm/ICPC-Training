#include <bits/stdc++.h>
using namespace std;

const int N = 505;
string a[N];
string b[N][N];
int cnt[N];
bool F[N];
void solve()
{
    memset(F, 0, sizeof(F));
    memset(cnt, 0, sizeof(cnt));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> b[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j][i])
            {
                cnt[j]++;
                F[i] = 1;
            }
        }
    int maxk = 0;
    bool flag = 1;
    for (int i = 1; i <= m; i++)
        maxk = max(cnt[i], maxk);
    for (int i = 1; i <= n; i++)
        flag &= F[i];
    if (flag)
        cout << n + 2 * (n - maxk) << endl;
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