#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2021/C1
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m), bb;
    for (auto &x : a)
        cin >> x;
    vector<bool> t(n + 1, 0);
    for (auto &x : b)
        cin >> x;
    for (int i = 0; i < m; i++)
    {
        if (!t[b[i]])
            bb.push_back(b[i]), t[b[i]] = 1;
    }
    int mm = bb.size();
    bool ok = 1;
    if (mm > n)
    {
        cout << "TIDAK\n";
        return;
    }
    for (int i = 0, j = 0; i < mm && j < n; i++, j++)
    {
        if (a[j] != bb[i])
        {
            ok = 0;
            break;
        }
    }
    if (ok)
        cout << "YA\n";
    else
        cout << "TIDAK\n";
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