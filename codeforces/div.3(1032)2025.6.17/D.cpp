#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<array<int, 2>> op;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                op.push_back({1, j + 1}), swap(a[j], a[j + 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (b[j] > b[j + 1])
                op.push_back({2, j + 1}), swap(b[j], b[j + 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= b[i])
            op.push_back({3, i + 1}), swap(a[i], b[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                op.push_back({1, j + 1}), swap(a[j], a[j + 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (b[j] > b[j + 1])
                op.push_back({2, j + 1}), swap(b[j], b[j + 1]);
        }
    }
    cout << op.size() << '\n';
    for (auto [p, pos] : op)
    {
        cout << p << ' ' << pos << '\n';
    }
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