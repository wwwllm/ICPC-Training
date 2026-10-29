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
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();
    //cout << a[n - 3] << " " << a[n - 2] << " " << a[n - 1] << '\n';
    if (a.size() < 3)
    {
        if (a.size() <= 1)
            cout << -1 << '\n';
        else
            cout << a[n - 2] % a[n - 1] << '\n';
    }
    else
        cout << max(a[n - 3], a[n - 1] % a[n - 2]) << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}