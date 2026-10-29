#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ranges::sort(a);
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (a[i] % a[0] == 0)
            continue;
        if (a[0] <= (a[i] + 1) / 2 - 1)
            continue;
        cout << a[0] / 2 << '\n';
        return;
    }
    cout << a[0] << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}