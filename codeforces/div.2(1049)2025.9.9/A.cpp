#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (auto x : s)
    {
        if (x == '1')
            cnt++;
    }
    int ans = 0;
    for (int i = n - 1; i > n - 1 - cnt; i--)
    {
        if (s[i] == '0')
            ans++;
    }
    cout << ans << '\n';
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