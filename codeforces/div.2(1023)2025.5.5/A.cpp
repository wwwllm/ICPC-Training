#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a[0];
    bool ok = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        if (a[i] != a[0])
            ok = 1;
    }
    if (!ok)
        cout << "No\n";
    else
    {
        cout << "Yes\n";
        int ma = *max_element(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            if (a[i] == ma)
                cout << 2 << ' ';
            else
                cout << 1 << ' ';
        }
        cout << '\n';
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