#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<ll, int> mp;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    bool ok = 0, ans = 0;
    int pre = 0;
    for (auto [d, cnt] : mp)
    {
        if (cnt >= 4)
        {
            ans = 1;
            break;
        }
        if (cnt >= 2)
        {
            if (ok && pre == d - 1)
                ans = 1;
            else
                ok = 1, pre = d;
        }
        else
        {
            if (ok && pre == d - 1)
                pre++;
            else
                ok = 0, pre = 0;
        }
    }
    cout << (ans ? "Yes\n" : "No\n");
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