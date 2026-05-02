#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector ne(n + 1, vector<int>(32)), sum(n + 1, vector<int>(32));
    for (int i = 1; i <= n; i++)
    {
        cin >> ne[i][0];
        sum[i][0] = i;
    }

    for (int b = 1; b < 32; b++)
    {
        for (int i = 1; i <= n; i++)
        {
            ne[i][b] = ne[ne[i][b - 1]][b - 1];
            sum[i][b] = sum[ne[i][b - 1]][b - 1] + sum[i][b - 1];
        }
    }

    while (q--)
    {
        int t, pos;
        cin >> t >> pos;
        int res = 0;
        for (int b = 0; b < 32; b++)
        {
            if ((t >> b) & 1)
            {
                res += sum[pos][b];
                pos = ne[pos][b];
            }
        }
        cout << res << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
