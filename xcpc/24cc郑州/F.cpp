#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    vector tim(11, vector<int>(n));
    int cur = 0;
    for (int d = 1; d <= 10; d++)
    {
        for (int i = 0; i < n; i++)
        {
            int beg = max(cur, a[i][0] - 1 + (d - 1) * k);
            tim[d][i] = beg + a[i][1];
            cur = tim[d][i];
        }
    }
    // for (int i = 1; i <= 5; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cerr << tim[i][j] << " \n"[j == n - 1];
    //     }
    // }
    while (q--)
    {
        int x, pos;
        cin >> x >> pos;
        pos--;
        int time = -1;
        if (x <= 10)
        {
            time = tim[x][pos];
        }
        else
        {
            int u = tim[10][pos] - tim[9][pos];
            time = tim[10][pos] + (x - 10) * u;
        }
        int d = (time + k - 1) / k;
        int h = time % k;
        if (h == 0)
            h = k;
        cout << d << ' ' << h << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}