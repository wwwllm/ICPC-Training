#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        c1 += a[i] >= 3;
        c2 += a[i] >= 2;
    }
    if (c1 > 0 || c2 > 1)
        cout << "YES\n";
    else
        cout << "NO\n";
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