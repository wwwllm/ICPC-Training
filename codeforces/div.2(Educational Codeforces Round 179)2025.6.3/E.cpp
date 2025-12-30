#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    set<int> ba, bc, cb, ca;
    for (int i = 1; i <= q; i++)
    {
        char x, y;
        cin >> x >> y;
        if (x == 'b' && y == 'a')
            ba.insert(i);
        else if (x == 'b' && y == 'c')
            bc.insert(i);
        else if (x == 'c' && y == 'b')
            cb.insert(i);
        else if (x == 'c' && y == 'a')
            ca.insert(i);
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a')
            continue;
        else if (s[i] == 'b')
        {
            if (ba.size())
                s[i] = 'a', ba.erase(ba.begin());
            else if (bc.size() && ca.size())
            {
                auto x = *bc.begin();
                if (ca.lower_bound(x) != ca.end())
                    bc.erase(x), ca.erase(ca.lower_bound(x)), s[i] = 'a';
            }
        }
        else
        {
            if (ca.size())
                s[i] = 'a', ca.erase(ca.begin());
            else if (cb.size() && ba.size() && ba.lower_bound(*cb.begin()) != ba.end())
            {
                auto x = *cb.begin();
                if (ba.lower_bound(x) != ba.end())
                    cb.erase(x), ba.erase(ba.lower_bound(x)), s[i] = 'a';
            }
            else if (cb.size())
                s[i] = 'b', cb.erase(cb.begin());
        }
    }
    cout << s << '\n';
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
