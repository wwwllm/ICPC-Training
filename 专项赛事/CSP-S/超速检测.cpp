#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m, L, V;
    cin >> n >> m >> L >> V;
    vector<array<int, 2>> q;
    vector<array<int, 3>> c(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i][0] >> c[i][1] >> c[i][2];
    }
    vector<int> p(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> p[i];
    auto cmp = [&](int d, int v, int a) -> int
    {
        int l = lower_bound(p.begin() + 1, p.end(), d) - p.begin() - 1, r = m + 1;
        if (a == 0)
        {
            return 0;
        }
        while (l + 1 != r)
        {
            int mid = l + r >> 1;
            if ((a > 0 && V * V < v * v + 2 * a * (p[mid] - d)) || (a < 0 && V * V >= v * v + 2 * a * (p[mid] - d)))
                r = mid;
            else
                l = mid;
        }
        if (a < 0)
            return l;
        else
            return r;
    };
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {

        int x = cmp(c[i][0], c[i][1], c[i][2]);
        if (c[i][0] > p[m])
            continue;
        if (c[i][2] == 0 && c[i][1] > V && c[i][0] <= p[m])
        {
            cnt++;
            q.push_back({lower_bound(p.begin() + 1, p.end(), c[i][0]) - p.begin(), m});
            continue;
        }
        if (x <= m && x >= lower_bound(p.begin() + 1, p.end(), c[i][0]) - p.begin())
        {
            if (c[i][2] > 0)
            {
                q.push_back({x, m});
                cnt++;
            }
            else if (c[i][2] < 0 && c[i][1] > V)
            {
                q.push_back({lower_bound(p.begin() + 1, p.end(), c[i][0]) - p.begin(), x});
                cnt++;
            }
        }
    }
    cout << cnt << ' ';
    int ans = 0;
    sort(q.begin(), q.end(), [&](array<int, 2> a, array<int, 2> b)
         { return a[1] < b[1]; });
    int tmp = -1;
    // for (auto [l, r] : q)
    //     cout << l << ' ' << r << '\n';
    for (int i = 0; i < q.size(); i++)
    {
        if (tmp >= q[i][0])
        {
            continue;
        }
        tmp = q[i][1];
        ans++;
    }
    cout << m - ans << '\n';
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