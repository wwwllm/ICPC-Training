#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int l = n / 97, r = n % 97;
    if (l == 0)
    {
        cout << "No\n";
        return;
    }
    vector<int> a(l, 97);
    for (int i = 0; i < l && r; i++)
    {
        int d = min(r, 122 - 97);
        a[i] += d;
        r -= d;
    }
    if (r != 0)
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    for (int i = 0; i < l; i++)
    {
        cout << char(a[i]);
    }
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}