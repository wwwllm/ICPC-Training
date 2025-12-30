#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2065/E
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (abs(n - m) > k || k > max(n, m))
    {
        cout << -1 << '\n';
        return;
    }
    if (n > m)
    {
        for (int i = 1; i <= k; i++)
            cout << 0, n--;
        if (m)
            cout << 1, m--;
    }
    else
        for (int i = 1; i <= k; i++)
            cout << 1, m--;
    while (n > 0 || m > 0)
    {
        if (n)
            cout << 0, n--;
        if (m)
            cout << 1, m--;
    }
    cout << "\n";
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