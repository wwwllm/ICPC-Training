#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector g(n, vector<int>(m, 0));
    if (gcd(n, m) != 1)
    {
        cout << "NO\n";
        return;
    }
    else
    {
        cout << "YES\n";
        int x = 0, y = 0;
        for (int i = 1; i <= n * m; i++)
        {
            g[x][y] = i;
            if (i % n == 0)
            {
                int cnt = i / n;
                if (cnt & 1)
                    y = (y + i) % m;
                else
                    y = ((y - i) % m + m) % m;
            }
            else
            {
                int f = i % n;
                if (f & 1)
                    x = (x + i) % n;
                else
                    x = ((x - i) % n + n) % n;
            }
        }
    }
    for (auto a : g)
    {
        for (auto ele : a)
            cout << ele << ' ';
        cout << '\n';
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