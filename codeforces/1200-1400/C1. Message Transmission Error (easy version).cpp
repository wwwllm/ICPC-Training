#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2010/C1
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    for (int len = n / 2 + 1; len < n; len++)
    {
        string sa = s.substr(0, len);
        string sb = s.substr(n - len);
        if (sa == sb)
        {
            cout << "YES\n";
            cout << sa << '\n';
            return;
        }
    }
    cout << "NO\n";
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
