#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    bool flag = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (count(a.begin(), a.end(), 1) == 0)
        flag = 1;
    if (count(a.begin(), a.end(), 0) == 0)
        flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0 && a[i - 1] == 0)
            flag = 1;
    }
    if (!flag)
        cout << "NO\n";
    else
        cout << "YES\n";
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}