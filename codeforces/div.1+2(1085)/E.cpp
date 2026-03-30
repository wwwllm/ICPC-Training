#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = n;
    bool ok = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > n || a[i - 1] < a[i] || a[i] < (n - i))
            ok = 0;
    }
    if (ok)
        cout << "YES\n";
    else
    {
        cout << "NO\n";
        return;
    }
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; i++)
        vis[a[i]] = 1;
    int r = n;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == a[i - 1])
        {
            r--;
            while (vis[r])
                r--;
            cout << r << ' ';
        }
        else
        {
            cout << inf << ' ';
        }
    }
    cout << '\n';
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