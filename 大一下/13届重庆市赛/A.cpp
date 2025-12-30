#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int d = 0;
    while (1)
    {
        bool ok = 1;
        for (auto x : a)
        {
            if (a[0] != x)
                ok = 0;
        }
        if (ok)
            break;
        d++;
        vector<int> temp = a;
        for (int i = 0; i < n; i++)
        {
            temp[i] |= a[(i + d) % n];
        }
        a = temp;
    }
    cout << d << '\n';
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