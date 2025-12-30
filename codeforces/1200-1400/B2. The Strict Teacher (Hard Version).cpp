#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2005/B2
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(m), query(q);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    for (auto &x : query)
        cin >> x;
    for (auto x : query)
    {
        int posr = lower_bound(a.begin(), a.end(), x) - a.begin();
        if (posr != a.size() && a[posr] == x)
        {
            cout << 0 << '\n';
            continue;
        }
        int l;
        if (posr == 0)
            l = a[posr] - 1;
        else if (posr == a.size())
            l = n - a.back();
        else
        {
            l = (a[posr] - a[posr - 1]) / 2;
        }
        cout << l << '\n';
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
};