#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    if (m < n || m > (n + 1) * n / 2)
    {
        cout << -1 << '\n';
        return;
    }
    int k = m - n;
    set<int> p;
    for (int i = n; i > 1; i--)
    {
        if (k >= i - 1)
            p.insert(i), k -= i - 1;
    }
    if (p.size())
        cout << *p.rbegin() << '\n';
    else
        cout << 1 << '\n';
    int pre = 1;
    for (auto u : p)
    {
        cout << pre << ' ' << u << '\n';
        pre = u;
    }
    for (int i = 2; i <= n; i++)
    {
        if (p.count(i) == 0)
            cout << 1 << ' ' << i << '\n';
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