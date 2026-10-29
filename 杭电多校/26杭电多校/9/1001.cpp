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
    int sum = 0;
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        if (r < 2 * a[i])
        {
            sum += 2 * a[i] - r;
            r = a[i];
        }
        else
            r -= a[i];
    }
    cout << sum << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
