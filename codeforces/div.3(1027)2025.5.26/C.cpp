#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int res = a[0];
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] <= res + 1)
            continue;
        else
        {
            ans++;
            res = a[i];
        }
    }
    cout << ans << '\n';
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