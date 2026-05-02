#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    s = '(' + s + ')';
    t = '(' + t + ')';
    auto calc = [&](string s) -> array<int, 2>
    {
        vector<int> stk;
        int n = s.size();
        vector<int> nxt(n);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                stk.push_back(i);
            else
            {
                int p = stk.back();
                stk.pop_back();
                nxt[p] = i;
            }
        }
        int dep = 0;
        int l = 0, r = n - 1;
        while (l < r && nxt[l] == r)
        {
            l++;
            r--;
            dep++;
        }
        auto dfs = [&](auto &&self, int l, int r) -> int
        {
            if (l + 1 == r)
                return 1;
            int res = 0;
            int ll = l + 1;
            while (ll < r)
            {
                res += self(self, ll, nxt[ll]);
                ll = nxt[ll] + 1;
            }
            return res;
        };
        return {dep, dfs(dfs, 0, n - 1)};
    };
    if (calc(s) == calc(t))
        cout << "YES\n";
    else
        cout << "NO\n";
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
