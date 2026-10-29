#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5;
void solve()
{
    int n;
    string s;
    cin >> s;
    n = s.size();
    if (s[0] == '0' && s[1] == '0')
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                cout << s.substr(i) << '\n';
                return;
            }
        }
        cout << "0\n";
        return;
    }
    auto cmp = [&](string &a, string &b) -> bool
    {
        if (a.size() != b.size())
        {
            return a.size() < b.size();
        }
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
                return a[i] < b[i];
        }
        return 0;
    };
    auto calc = [&](string a, string b) -> string
    {
        ranges::reverse(a);
        ranges::reverse(b);
        string res = "";
        int n = max(a.size(), b.size());
        for (int i = 0; i < n; i++)
        {
            int u = 0, v = 0;
            if (i < a.size())
                u = a[i] - '0';
            if (i < b.size())
                v = b[i] - '0';
            res += u ^ v + '0';
        }
        ranges::reverse(res);
        for (int i = 0; i < res.size(); i++)
        {
            if (res[i] == '1')
                return res.substr(i);
        }
        return "0";
    };
    string ans = "0";
    for (auto idx : vector<int>{1, 2, n - 2, n - 3})
    {
        if (idx < 1 || idx > n - 2)
        {
            continue;
        }
        cerr << s.substr(0, idx) << ' ' << s.substr(idx + 1) << '\n';
        auto tmp = calc(s.substr(0, idx), s.substr(idx + 1));
        if (cmp(ans, tmp))
        {
            ans = tmp;
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}