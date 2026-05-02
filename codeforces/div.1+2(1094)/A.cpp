#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    bool ok = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x == 100)
        {
            ok = 1;
        }
    }
    cout << (ok ? "Yes\n" : "No\n");
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