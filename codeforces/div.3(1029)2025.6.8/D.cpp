#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    bool ok = 1;
    int d = a[1] - a[0];
    int u = (a[0] - d) / (n + 1);
    int p = d + u;
    if (p < 0 || u < 0)
    {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != u * (n + 1) + d * (i + 1))
            ok = 0;
    }
    cout << (ok ? "YES\n" : "NO\n");
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