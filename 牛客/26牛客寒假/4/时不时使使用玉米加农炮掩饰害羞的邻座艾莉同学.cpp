#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector a(n + 2, vector<int>(m + 2));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    int maxx = -1, maxy = -1, ma = 0;
    vector aa(n + m + 1, vector<int>(n + m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            aa[i + j][i - j + m] = a[i][j];
        }
    }
    auto check = [&](int x, int y) -> bool
    {
        int xx = x + y - m, yy = x - y + m;
        if ((xx & 1) || (yy & 1))
            return 0;
        xx /= 2, yy /= 2;
        return xx >= 1 && xx <= n && yy >= 1 && yy <= m;
    };
    auto clac = [&](int x, int y)
    {
        int res = 0;
        for (int i = max(x - 2, 0LL); i <= min(x + 2, n + m); i++)
        {
            for (int j = max(y - 2, 0LL); j <= min(y + 2, n + m); j++)
                res += aa[i][j];
        }
        if (res > ma)
        {
            maxx = x, maxy = y;
            ma = res;
        }
    };
    for (int i = 0; i <= n + m; i++)
    {
        for (int j = 0; j <= n + m; j++)
        {
            if (check(i, j))
                clac(i, j);
        }
    }
    while (q--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        aa[x + y][x - y + m] += z;
        for (int i = max(x + y - 2, 0LL); i <= min(x + y + 2, n + m); i++)
        {
            for (int j = max(x - y - 2 + m, 0LL); j <= min(x - y + 2 + m, n + m); j++)
                if (check(i, j))
                    clac(i, j);
        }
        cout << (maxx + maxy - m) / 2 << ' ' << (maxx - maxy + m) / 2 << '\n';
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