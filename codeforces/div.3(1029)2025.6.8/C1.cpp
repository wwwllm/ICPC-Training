#include <bits/stdc++.h>
// #define int long long
using namespace std;

set<int> s, tmp;
bool ok()
{
    for (auto e1 : s)
    {
        if (tmp.count(e1))
            continue;
        else
            return 0;
    }
    return 1;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    s.clear(), tmp.clear();
    s.insert(a[0]);
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        tmp.insert(a[i]);
        if (ok())
        {
            cnt++;
            s = tmp;
            tmp.clear();
        }
    }
    cout << cnt << "\n";
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