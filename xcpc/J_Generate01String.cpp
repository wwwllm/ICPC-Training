#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105909
void solve()
{
    string s;
    cin >> s;
    int c0 = 0, c1 = 0;
    for (auto c : s)
        c0 += c == '0', c1 += c == '1';
    if (c0 != c1)
    {
        cout << -1 << '\n';
        return;
    }
    vector<array<int, 2>> ans;
    int n = s.size();
    int p = 1;
    for (int i = 0; i < n; i++)
    {
        int sum = s[i] == '1' ? 1 : -1;
        int j = i + 1;
        while (sum != 0 && j < n)
            sum += s[j++] == '1' ? 1 : -1;
        int op = s[i] == '0' ? 1 : 2;
        int ci = 0;
        for (int k = i; k < j; k++)
        {
            if (s[k] == s[i])
                ci++;
            if (s[k] != s[i] && s[k] != s[k - 1])
            {
                for (int i = 0; i < ci; i++)
                {
                    ans.push_back({p, op});
                }
                ci = 0;
            }
            if (s[k] != s[i])
                p++;
        }
        i = j - 1;
    }
    cout << ans.size() << '\n';
    for (auto [pos, op] : ans)
        cout << pos << ' ' << op << '\n';
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