#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/gym/105941
void solve()
{
    int n;
    cin >> n;
    if (n == 4)
    {
        cout << "-1\n";
        return;
    }
    if (n == 3)
    {
        cout << "1 2\n1 3\n";
        return;
    }
    if (n == 2)
    {
        cout << "1 2\n";
        return;
    }
    vector<array<int, 2>> e;
    if (n % 3 == 0)
    {
        int d = 2 * n / 3;
        for (int i = 1; i <= d; i++)
            e.push_back({i, i + 1});
        for (int i = d + 2; i <= n; i++)
        {
            e.push_back({2, i});
        }
    }
    else if (n % 3 == 1)
    {
        int d = (2 * n - 2) / 3;
        for (int i = 1; i <= d; i++)
            e.push_back({i, i + 1});
        for (int i = d + 2; i <= n; i++)
        {
            e.push_back({3, i});
        }
    }
    else
    {
        int d = (2 * n - 1) / 3;
        for (int i = 1; i <= d; i++)
            e.push_back({i, i + 1});
        for (int i = d + 2; i <= n; i++)
        {
            e.push_back({2, i});
        }
    }
    for (auto [u, v] : e)
        cout << u << ' ' << v << '\n';
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