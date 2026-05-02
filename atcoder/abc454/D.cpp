#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    string a, b;
    cin >> a >> b;
    auto change = [&](string s)
    {
        vector<int> stk;
        string res = "";
        for (auto c : s)
        {
            res += c;
            while (res.size() >= 4)
            {
                int l = res.size();
                if (res.substr(l - 4, 4) == "(xx)")
                {
                    res.pop_back(), res.pop_back(), res.pop_back(), res.pop_back();
                    res += "xx";
                }
                else
                    break;
            }
        }
        return res;
    };
    if (change(a) == change(b))
        cout << "Yes\n";
    else
        cout << "No\n";
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