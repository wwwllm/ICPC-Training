#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/gym/105941
void solve()
{
    string s;
    cin >> s;
    array<int, 26> cnt = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        int res = 0;
        for (auto c : s)
        {
            int u = c - 'A';
            u = (u + i) % 26;
            res += cnt[u];
        }
        ans = max(ans, res);
    }
    cout << ans << '\n';
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