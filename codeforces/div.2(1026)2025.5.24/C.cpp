#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> d(n), l(n), r(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    vector<int> p;
    int L = 0, R = 0;
    for (int i = 0; i < n; i++)
    {
        if (d[i] == -1)
            p.push_back(i), R++;
        else
            L += d[i], R += d[i];
        while (L < l[i])
        {
            if (p.empty())
            {
                cout << -1 << '\n';
                return;
            }
            L++;
            d[p.back()] = 1;
            p.pop_back();
        }
        while (R > r[i])
        {
            if (p.empty())
            {
                cout << -1 << '\n';
                return;
            }
            R--;
            d[p.back()] = 0;
            p.pop_back();
        }
    }
    for (auto it : d)
        cout << max(0,it) << ' ';
    cout << '\n';
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