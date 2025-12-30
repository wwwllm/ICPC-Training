#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> b(n), t(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        t[b[i]]++;
    }
    bool ok = 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (t[i] % i == 0)
        {
            cnt += t[i];
        }
        else
            ok = 0;
    }
    if (!ok || cnt != n)
    {
        cout << -1 << '\n';
        return;
    }
    int p = 1;
    vector<int> ans(n);
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        int cnt = t[i];
        while (cnt)
        {
            mp[i].push_back(p++);
            cnt -= i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] == 1)
        {
            ans[i] = mp[b[i]].back();
            mp[b[i]].pop_back();
            t[b[i]]--;
        }
        else if (t[b[i]] % b[i] == 1)
        {
            ans[i] = mp[b[i]].back();
            mp[b[i]].pop_back();
            t[b[i]]--;
        }
        else
        {
            ans[i] = mp[b[i]].back();
            t[b[i]]--;
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];
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