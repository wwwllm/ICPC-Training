#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/1993/C
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    int l = a[n - 1], r = a[n - 1] + k - 1;
    for (int i = 0; i < n; i++)
    {
        if (((a[n - 1] - a[i]) / k) & 1)
            l = max(l, a[i] + ((a[n - 1] - a[i]) / k + 1) * k);
        else
            r = min(r, a[i] + ((a[n - 1] - a[i]) / k + 1) * k - 1);
    }
    if (l <= r)
        cout << l << '\n';
    else
        cout << -1 << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}