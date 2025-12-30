#include <bits/stdc++.h>
using namespace std;

const int N = 810;
int ans[2 * N], t[2 * N];
void solve()
{
    memset(t, 0, sizeof(t));
    int n;
    cin >> n;
    int x;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            ans[i + j] = x;
            t[x] = 1;
        }
    for (int i = 1; i <= 2 * n; i++)
        if (!t[i])
            cout << i << ' ';
    for (int i = 2; i <= 2 * n; i++)
        cout << ans[i] << ' ';
    cout << endl;
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