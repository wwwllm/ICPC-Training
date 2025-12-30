#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, j, k;
    cin >> n >> j >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (k == 1)
    {
        int ma = *max_element(a.begin() + 1, a.end());
        if (a[j] == ma)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else
        cout << "YES\n";
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