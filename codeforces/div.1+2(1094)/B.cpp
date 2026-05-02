#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if ((i + 1) & 1)
            a.push_back(x);
        else
            b.push_back(x);
    }
    ranges::sort(a);
    ranges::sort(b);
    int ans = 0;
    bool okb = 0, oka = 0;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        if (x & 1)
        {
            if (a.size() && (!oka || a.back() > 0))
                a.pop_back(), oka = 1;
        }
        else
        {
            if (b.size() && (!okb || b.back() > 0))
                b.pop_back(), okb = 1;
        }
    }
    for (auto x : a)
        ans += x;
    for (auto x : b)
        ans += x;
    cout << ans << '\n';
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