#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/106380
const int inf = 1e18;
void solve()
{
    int n;
    cin >> n;
    vector<array<int, 3>> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    for (int i = 0; i < 3; i++)
    {
        int c = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[j][i] == 1)
                c++;
        }
        if (c == n)
        {
            cout << 1 << '\n';
            return;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
                continue;
            int c1 = 0, c2 = 0, c3 = 0;
            for (int k = 1; k <= n; k++)
            {
                if (a[k][i] == 1)
                    c1++;
                else if (a[k][i] == 1 && a[k][j] == 1)
                    c2++;
                else if (a[k][j] == 1)
                    c3++;
            }
            int len = c1 + c3;
            if (len == n)
            {
                cout << 2 << '\n';
                return;
            }
        }
    }
    cout << 3 << '\n';
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