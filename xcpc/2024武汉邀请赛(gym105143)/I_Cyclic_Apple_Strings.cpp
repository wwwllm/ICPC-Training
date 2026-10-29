#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/gym/105143
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == '1' && s[i + 1] == '0')
            cnt++;
    }
    cout << cnt << '\n';
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