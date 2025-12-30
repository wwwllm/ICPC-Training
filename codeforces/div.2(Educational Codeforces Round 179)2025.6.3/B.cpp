#include <bits/stdc++.h>
using namespace std;
// using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    a[0]=1,a[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    int d = a[n] + a[n - 1], y = a[n];
    while (m--)
    {
        int w, l, h;
        cin >> w >> l >> h;
        int ma = max({l, h, w});
        int mi = min({l, h, w});
        if (ma >= d && mi >= y)
            cout << 1;
        else
            cout << 0;
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