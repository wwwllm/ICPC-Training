#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> a(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> a[i][0] >> a[i][1];
    ranges::sort(a);
    for (int i = 1; i <= m; i++)
    {
        int d = a[i][0] - a[i - 1][0];
        if (a[i][1] - a[i - 1][1] == d || a[i][1]< d)
            continue;
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
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