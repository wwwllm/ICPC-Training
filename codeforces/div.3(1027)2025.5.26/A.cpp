#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int res = 0;
    for (auto it : s)
    {
        int u = it - '0';
        res = res * 10 + u;
    }
    int m = sqrt(res);
    if (m * m == res)
    {
        cout << 0 << ' ' << m << '\n';
    }
    else
        cout << -1 << '\n';
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