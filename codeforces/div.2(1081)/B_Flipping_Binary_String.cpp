#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> p0, p1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            p1.pb(i + 1);
        else
            p0.pb(i + 1);
    }
    int cnt0 = p0.size(), cnt1 = p1.size();
    vector<int> ans;
    if ((cnt0 % 2) == 1)
    {
        cout << cnt0 << '\n';
        if (cnt0 == 0)
            return;
        for (auto idx : p0)
            cout << idx << ' ';
        cout << '\n';
    }
    else if ((cnt1 % 2) == 0)
    {
        cout << cnt1 << '\n';
        if (cnt1 == 0)
            return;
        for (auto idx : p1)
            cout << idx << ' ';
    }
    else
    {
        cout << -1 << '\n';
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