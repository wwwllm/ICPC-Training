#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> p(n);
    for (auto &x : p)
        cin >> x;
    sort(p.begin(), p.end());
    int l = p[0], r = p[n - 1];
    if (s < l)
    {
        cout << r - s << '\n';
    }
    else if (s > r)
    {
        cout << s - l << '\n';
    }
    else
        cout << r - l + min(s - l, r - s) << '\n';
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