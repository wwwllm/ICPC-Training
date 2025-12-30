#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int L, R;
    cin >> L >> R;
    int ans = 0;
    vector<int> l, r;
    while (L)
    {
        l.push_back(L % 10);
        L /= 10;
    }
    while (R)
    {
        r.push_back(R % 10);
        R /= 10;
    }
    bool ok = 1;
    int n = l.size();
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (l[i] == r[i])
            cnt++;
        else
            break;
    }
    int c1 = 0, c0 = 0;
    if (cnt == n || l[n - 1 - cnt] + 1 < r[n - 1 - cnt])
    {
        cout << cnt * 2 << '\n';
        return;
    }
    int pos = n - 1 - cnt;
    for (int i = pos - 1; i >= 0; i--)
    {
        if (l[i] == 9)
            c0++;
        else
            break;
    }
    for (int i = pos - 1; i >= 0; i--)
    {
        if (r[i] == 0)
            c1++;
        else
            break;
    }
    cout << cnt * 2 + 1 + min(c1, c0) << '\n';
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