#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/1986/D
void solve()
{
    string s;
    int n;
    cin >> n;
    cin >> s;
    bool ok1 = 1, ok0 = 0;
    for (auto it : s)
    {
        if (it != '1')
            ok1 = 0;
        if (it == '0')
            ok0 = 1;
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < n - 1; i++)
    {
        vector<int> a;
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                a.push_back(10 * (s[j] - '0') + s[j + 1] - '0');
            else if (j == i + 1)
                continue;
            else
                a.push_back(s[j] - '0');
        }
        int cnt0 = count(a.begin(), a.end(), 0), cnt1 = count(a.begin(), a.end(), 1);
        int res = 0;
        if (cnt0 > 0)
            res = 0;
        else if (cnt1 == a.size())
            res = 1;
        else
        {
            for (auto it : a)
                if (it > 1)
                    res += it;
        }
        ans = min(ans, res);
    }
    cout << ans << '\n';
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