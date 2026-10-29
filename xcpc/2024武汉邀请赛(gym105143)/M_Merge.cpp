#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105143
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    multiset<int> s;
    for (int i = 1; i <= n; i++)
    {
        s.insert(a[i]);
    }
    auto work = [&](int x) -> bool
    {
        if (x % 2 == 0)
            return 0;
        if (s.find(x) != s.end())
        {
            s.erase(s.find(x));
            return 1;
        }
        bool ok = 1;
        vector<int> num;
        while (1)
        {
            int u = x / 2, v = x - x / 2;
            if (u & 1)
                swap(u, v);
            if (!(s.find(u) != s.end()))
            {
                ok = 0;
                break;
            }
            num.push_back(u);
            s.erase(s.find(u));
            if (s.find(v) != s.end())
            {
                num.push_back(v);
                s.erase(s.find(v));
                break;
            }
            else
            {
                x = v;
            }
        }
        if (!ok)
        {
            for (auto u : num)
                s.insert(u);
        }
        return ok;
    };
    ranges::sort(a, greater<int>());
    a.erase(unique(a.begin(), a.end()), a.end());
    vector<int> ans;
    for (auto v : a)
    {
        while (work(v * 2 + 1))
            ans.push_back(v * 2 + 1);
        while (work(v * 2 - 1))
            ans.push_back(v * 2 - 1);
    }
    while (s.size())
    {
        ans.push_back(*s.begin());
        s.erase(s.begin());
    }
    cout << ans.size() << '\n';
    for (auto x : ans)
        cout << x << ' ';
    cout << '\n';
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