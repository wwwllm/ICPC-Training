#include <bits/stdc++.h>
#define int long long
using namespace std;
// using ll = long long;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        int c = i / 2;
        if (i % 2 == 0)
        {
            cout << a[c] << " " << a[m - 1 - c] << " " << a[c] << " " << a[m - 1 - c] << " " << a[c] << " " << a[m - 1 - c] << "\n";
        }
        else
        {
            cout << a[m - 1 - c] << " " << a[c] << " " << a[m - 1 - c] << " " << a[c] << " " << a[m - 1 - c] << " " << a[c] << "\n";
        }
    }
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