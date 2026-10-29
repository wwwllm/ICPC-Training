#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 10, M = 1e4 + 10;
int f[M];
bool ans[M];
void solve()
{
    int n, m;
    cin >> n >> m;
    while (n--)
    {
        for (int i = 1; i <= m; i++)
        {
            int x;
            cin >> x;
            f[x] = i;
        }
        for (int i = m; i >= 1; i--)
        {
            if (!ans[f[i]])
            {
                ans[f[i]] = 1;
                break;
            }
        }
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << ' ';
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    //    cin >> t;
    while (t--)
        solve();
    return 0;
}
