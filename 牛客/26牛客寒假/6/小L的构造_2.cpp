#include <bits/stdc++.h>
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n < 6)
    {
        if (n == 4)
            cout << "3 4 2 1\n";
        else
            cout << -1 << '\n';
        return;
    }
    vector a(3, vector<int>{});
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            a[0].pb(i);
        else if (i % 3 == 0)
            a[1].pb(i);
        else
            a[2].pb(i);
    }
    while (a[1].size() > 2 && a[2].size())
    {
        ans.pb(a[2].back());
        a[2].pop_back();
        ans.pb(a[1].back());
        a[1].pop_back();
        ans.pb(a[1].back());
        a[1].pop_back();
    }
    while (a[0].size() > 2 && a[2].size())
    {
        ans.pb(a[2].back());
        a[2].pop_back();
        ans.pb(a[0].back());
        a[0].pop_back();
        ans.pb(a[0].back());
        a[0].pop_back();
    }
    while (a[0].size())
        ans.pb(a[0].back()), a[0].pop_back();
    while (a[1].size())
        ans.pb(a[1].back()), a[1].pop_back();
    while (a[2].size())
        ans.pb(a[2].back()), a[2].pop_back();
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];
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