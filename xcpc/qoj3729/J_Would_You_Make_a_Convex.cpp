#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://qoj.ac/contest/3729
const int N = 1e5;
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
    int ans = 0;
    int l = -1, r = -1;
    for (int i = 0; i < n - 1; i++)
    {
        int s = a[i] + a[i + 1];
        int pos = ranges::lower_bound(a, s) - a.begin();
        int len = pos - i;
        if (ans < len)
        {
            ans = len;
            l = i, r = pos;
        }
    }
    if (ans < 3)
    {
        cout << 0 << '\n';
        return;
    }
    cout << ans << ' ';
    for (int i = l; i < r; i++)
    {
        cout << a[i] << " \n"[i == r - 1];
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}