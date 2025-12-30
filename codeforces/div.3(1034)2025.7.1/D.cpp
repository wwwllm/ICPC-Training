#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
            cnt++;
    }
    if (cnt <= k)
        cout << "Alice\n";
    else if (n >= 2 * k)
        cout << "Bob\n";
    else
        cout << "Alice\n";
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