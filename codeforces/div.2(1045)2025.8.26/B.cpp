#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int g = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        g = gcd(g, a[i]);
    }
    if (g > 1)
    {
        for (auto x : a)
            cout << x << ' ';
        cout << '\n';
        return;
    }
    if (k == 1)
    {
        for (auto &x : a)
        {
            if (x & 1)
                x++;
        }
    }
    else
    {
        g = k + 1;
        for (int i = 0; i < n; i++)
        {
            int cnt = a[i] % g;
            a[i] += cnt * k;
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