#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        cin >> b[i];
    vector<int> d(n + 1);
    vector<int> c(n + 1);
    for (int i = 1; i < n; i++)
    {
        c[i + 1] = (b[i] - c[i] + m) % m;
    }

    for (int i = 1; i <= n; i++)
        d[i] = (c[i] - a[i] + m) % m;
    vector<int> odd, even;
    int sumo = 0, sume = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
            odd.push_back(d[i]), sumo += d[i];
        else
            even.push_back(d[i]), sume += d[i];
    }
    ranges::sort(odd);
    ranges::sort(even);
    int res = 1e18;
    for (int i = 1; i <= n; i++)
    {
        int s;
        if (i & 1)
        {
            s = (a[i] - c[i] + m) % m;
        }
        else
            s = (c[i] - a[i] + m) % m;
        int ocnt = odd.end() - ranges::lower_bound(odd, m - s);
        int ecnt = ranges::lower_bound(even, s) - even.begin();
        res = min(res, sumo + sume + (ecnt - ocnt) * m + (n & 1) * s);
    }
    cout << res << '\n';
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