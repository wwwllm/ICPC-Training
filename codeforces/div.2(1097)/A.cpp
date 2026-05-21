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
    int res = 0;
    if (a[n - 1] > 0)
        res++;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i] + a[i + 1])
            a[i] = a[i + 1] + a[i];
        if (a[i] > 0)
            res++;
    }
    cout << res << '\n';
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