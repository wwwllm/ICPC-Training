#include <bits/stdc++.h>
using namespace std;

using PCI = pair<char, int>;
void solve()
{
    int n;
    cin >> n;
    vector<PCI> Q;
    unordered_map<int, vector<int>> mp;
    unordered_map<int, int> pos;
    for (int i = 0; i < n; i++)
    {
        char op;
        int x;
        cin >> op >> x;
        mp[x].push_back(i);
        Q.emplace_back(op, x);
        pos[x] = 0;
    }
    string ans = "";
    vector<int> stk;
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        auto [op, x] = Q[i];
        if (op == '+')
        {
            while (s.size() && s.count(x))
            {
                int u = stk.back();
                s.erase(u);
                stk.pop_back();
                ans.push_back('-');
            }
            ans.push_back('+');
            stk.push_back(x);
            s.insert(x);
            pos[x]++;
        }
        else if (op == 'T')
        {
            ans.push_back('?');
            pos[x]++;
        }
        else if (op == 'F')
        {
            while (s.size() && s.count(x))
            {
                int u = stk.back();
                s.erase(u);
                stk.pop_back();
                ans.push_back('-');
            }
            ans.push_back('?');
            pos[x]++;
        }
        while (stk.size())
        {
            int u = stk.back();
            int idx = pos[u];
            // cerr << u << ' ' << mp[u].size() << ' ' << idx << ' ' << mp[u][idx] << '\n';
            if (idx == mp[u].size() || Q[mp[u][idx]].first != 'T')
            {
                ans.push_back('-');
                stk.pop_back();
                s.erase(u);
            }
            else
                break;
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}