#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ranges::sort(a, greater<int>());
    map<int, int> mp;
    for (int i = 1; i < n; i++)
        mp[a[i]]++;
    int ma = 0, me = 0;
    vector<int> ans(n);
    ans[0] = a[0];
    int p = 1;
    for (int i = 0; i < n; i++)
    {
        if (mp[i])
        {
            ans[p++] = i;
            mp[i]--;
        }
    }
    for (auto [x, c] : mp)
    {
        while (c)
        {
            ans[p++] = x;
            c--;
        }
    }
    int sum = 0;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        ma = max(ans[i], ma);
        s.insert(ans[i]);
        while (s.count(me))
            me++;
        sum += ma + me;
    }
    cout << sum << '\n';
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