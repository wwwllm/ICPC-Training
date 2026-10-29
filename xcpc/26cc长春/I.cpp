#include <bits/stdc++.h>
using namespace std;

void solve(int pid)
{
    if (pid == 1)
    {
        int n;
        string s;
        cin >> n >> s;
        string res1 = "", res2 = "";
        res1 += s[0];
        res2 += s[0];
        res2 += s[0];
        int beg = s[0] - '0';
        for (int i = 1; i < n; i++)
        {
            beg ^= 1;
            if (s[i] == s[i - 1])
            {
                res1 += (beg + '0');
            }
            else
            {
                res1 += (beg + '0');
                res1 += (beg + '0');
            }
        }
        beg = s[0] - '0';
        for (int i = 1; i < n; i++)
        {
            beg ^= 1;
            if (s[i] == s[i - 1])
            {
                res2 += (beg + '0');
                res2 += (beg + '0');
            }
            else
            {
                res2 += (beg + '0');
            }
        }
        if (res1.size() > res2.size())
        {
            cout << res2.size() << '\n';
            cout << res2 << endl;
        }
        else
        {
            cout << res1.size() << '\n';
            cout << res1 << endl;
        }
    }
    else
    {
        int m;
        string s;
        cin >> m >> s;
        int op = s[0] == s[1];
        string ans = "";
        ans += s[0];
        for (int i = 1 + op; i < m; i++)
        {
            bool ok = op;
            if (i + 1 < m && s[i + 1] == s[i])
            {
                i++;
                ok ^= 1;
            }
            int u = ans.back() - '0';
            u ^= ok;
            ans += u + '0';
        }
        cout << ans.size() << '\n';
        cout << ans << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1, op;
    cin >> t >> op;
    while (t--)
        solve(op);
    return 0;
}