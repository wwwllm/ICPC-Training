#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    ranges::sort(a);
    for (int i = 0; i < n; i++)
    {
        if (c >= a[i])
        {

            int d = min(k, c - a[i]);
            k -= d;
            c += d + a[i];
        }
    }
    cout << c << '\n';
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