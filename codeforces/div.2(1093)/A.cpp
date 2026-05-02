#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    ranges::sort(a, greater<int>());
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1])
        {
            cout << -1 << '\n';
            return;
        }
    }
    for (auto x : a)
        cout << x << ' ';
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