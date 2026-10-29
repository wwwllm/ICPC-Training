#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://qoj.ac/problem/10477/statement/zh_cn
const int mod = 998244353;
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    auto calc = [&](string &s) -> vector<array<int, 2>>
    {
        vector<array<int, 2>> stk;
        int cur = 1;
        vector<array<int, 2>> res(n);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                stk.push_back({0, 0});
            }
            else if (s[i] == '1')
            {
                stk.push_back({cur, cur + 1});
                cur++;
            }
            else
            {
                int m = -1, l, r;
                m = stk.back()[0];
                res[m - 1][1] = r = stk.back()[1];
                stk.pop_back();
                res[m - 1][0] = l = stk.back()[0];
                stk.pop_back();
                stk.pop_back();
                stk.push_back({l, r});
            }
        }
        return res;
    };
    auto res1 = calc(s1);
    auto res2 = calc(s2);
    int size = ranges::count(s1, '1');
    int ans = 1;

    for (int i = 1; i < size; i++)
    {
        int m = i + 1;
        int l = max(res1[i][0], res2[i][0]);
        l = max(0LL, m - l);
        int r = min(res1[i][1], res2[i][1]);
        r = max(0LL, r - m);
        (ans *= l * r % mod) %= mod;
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