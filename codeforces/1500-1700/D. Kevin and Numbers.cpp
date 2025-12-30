
#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2061/D
void solve()
{
    int n, m;
    cin >> n >> m;
    multiset<int> a, b;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a.insert(x);
    }
    bool ok = 1;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        b.insert(x);
    }
    int t = n - m;
    while (a.size() && b.size())
    {
        int u = *b.rbegin(), v = *a.rbegin();
        b.erase(b.find(u));
        if (u < v)
        {
            ok = 0;
            break;
        }
        else if (u > v)
        {
            if (t <= 0)
            {
                ok = 0;
                break;
            }
            b.insert(u / 2);
            b.insert(u - u / 2);
            t--;
        }
        else if (u == v)
            a.erase(a.find(u));
    }
    if (b.size() || a.size())
        ok = 0;
    if (ok)
        cout << "Yes\n";
    else
        cout << "No\n";
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