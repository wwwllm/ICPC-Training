#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/gym/105481
void solve()
{
    unordered_set<string> s;
    string str;
    int n = 0;
    auto is_num = [&](string s) -> bool
    {
        bool ok;
        for (auto c : str)
        {
            if (c <= '9' && c >= 0)
            {
                continue;
            }
            else
                return 0;
        }
        return 1;
    };
    while (1)
    {
        cin >> str;
        if (is_num(str))
        {
            for (auto c : str)
            {
                n = n * 10 + c - '0';
            }
            break;
        }
        while (!((str.back() >= 'a' && str.back() <= 'z') || (str.back() >= 'A' && str.back() <= 'Z')))
            str.pop_back();
        if (str[0] >= 'A' && str[0] <= 'Z')
        {
            str[0] = str[0] - 'A' + 'a';
        }
        s.insert(str);
    }
    int cnt = s.size();
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (s.count(str))
        {
            s.erase(str);
            cnt--;
        }
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