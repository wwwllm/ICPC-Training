#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> cnt(3);
    for (auto &x : cnt)
        cin >> x;
    string s;
    cin >> s;
    int n = s.length();
    s += s;
    int ans = 0;
    for (int op = 0; op < 2; op++)
    {
        auto t = cnt;
        for (int i = op, j = op; i <= n; i += 2)
        {
            while (j + 2 <= i + n && t[s[j] - '0' + s[j + 1] - '0'] > 0)
            {
                t[s[j] - '0' + s[j + 1] - '0']--;
                j += 2;
            }
            ans = max(ans, j - i);
            t[s[i] - '0' + s[i + 1] - '0']++;
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}