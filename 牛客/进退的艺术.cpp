#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    auto b = a;
    sort(a.begin() + 1, a.end());

    auto pre = a;
    for (int i = 1; i <= n; i++)
        pre[i] += pre[i - 1];
    for (int i = 1; i <= n; i++)
    {
        auto p = upper_bound(a.begin() + 1, a.end(), m - b[i]) - a.begin();
        if (m - b[i] < b[i])
            cout << b[i] * (p - 1) - (pre[n] - pre[p - 1] - b[i]) << " ";
        else
            cout << b[i] * (p - 1) - (pre[n] - pre[p - 1]) - b[i] << " ";
    }
    cout << "\n";
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