#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/1991/C
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt0 = 0, cnt1 = 0;
    for (auto &x : a)
    {
        cin >> x;
        if (x & 1)
            cnt1++;
        else
            cnt0++;
    }
    if (cnt0 != 0 && cnt1 != 0)
    {
        cout << -1 << '\n';
        return;
    }
    vector<int> ans;
    int ma = *max_element(a.begin(), a.end());
    while (ma)
    {
        ans.push_back((ma + 1) / 2);
        ma = ma - (ma + 1) / 2;
    }
    cout << ans.size() << '\n';
    for (auto it : ans)
        cout << it << ' ';
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}