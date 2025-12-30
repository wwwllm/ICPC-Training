#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (m % k != 0)
    {
        int cnt = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cout << cnt << " ", cnt = cnt % k + 1;
            cout << endl;
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            int cnt = 1+(i&1);
            for (int j = 1; j <= m; j++)
            {
                cout << cnt << ' ';
                cnt = cnt % k + 1;
            }
            cout << endl;
        }
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