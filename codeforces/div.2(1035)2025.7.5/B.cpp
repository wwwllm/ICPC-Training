#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int qx, qy, px, py;
    cin >> px >> py >> qx >> qy;
    vector<int> a(n), dpl(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int sum = a[0], ma = a[0];
    for (int i = 1; i < n; i++)
    {
        ma = max(a[i], ma);
        sum += a[i];
    }
    int l = ma - (sum - ma);
    double d = sqrt((px - qx) * (px - qx) + (py - qy) * (py - qy));
    if (d >= l && d <= sum)
        cout << "Yes\n";
    else
        cout << "No\n";
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
};