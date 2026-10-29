#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    map<int, vector<int>> mp;
    int dmi = 1e9, dma = 0;
    for (int i = 1; i <= n; i++)
    {
        dmi = min(dmi, d[i]);
        dma = max(dma, d[i]);
        mp[d[i]].push_back(i);
    }
    if (mp[dmi].size() > 2)
    {
        cout << "No\n";
        return;
    }
    vector<array<int, 2>> e;
    if (mp[dmi].size() == 1)
    {
        if (dma != 2 * dmi - 1)
        {
            cout << "No\n";
            return;
        }
        vector<int> p = {mp[dmi][0]};
        for (int dep = dmi + 1; dep <= dma; dep++)
        {
            auto &pp = mp[dep];
            if (pp.empty())
            {
                cout << "No\n";
                return;
            }
            int siz = pp.size();

            if (siz == 1)
            {
                cout << "No\n";
            }
            for (int i = 0; i < siz; i++)
            {
                int j = i % p.size();
                e.push_back({p[j], pp[i]});
            }
            p = pp;
        }
    }
    if (mp[dmi].size() == 2)
    {
        if (dma != (dmi - 1) * 2)
        {
            cout << "No\n";
            return;
        }
        vector<int> p = mp[dmi];
        e.push_back({p[0], p[1]});
        for (int dep = dmi + 1; dep <= dma; dep++)
        {
            auto &pp = mp[dep];
            if (pp.empty())
            {
                cout << "No\n";
                return;
            }
            int siz = pp.size();

            if (siz == 1)
            {
                cout << "No\n";
            }
            for (int i = 0; i < siz; i++)
            {
                int j = i % p.size();
                e.push_back({p[j], pp[i]});
            }
            p = pp;
        }
    }
    if (e.size() == n - 1)
    {
        cout << "Yes\n";
        for (auto [u, v] : e)
            cout << u << ' ' << v << '\n';
    }
    else
    {
        cout << "No\n";
    }
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