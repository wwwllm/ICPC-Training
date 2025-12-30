#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int f[N][N],ans[N][N];
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            cin >> f[i][j];
    for (int i = 1; i <=n;i++)
        for (int j = 1; j <= m;j++)
            ans[j][i] = f[i][j];
    for (int i = 1; i <= m;i++){
        for (int j = 1; j <= n;j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}