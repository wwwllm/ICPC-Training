#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using PII = pair<ll, ll>;
const ll inf = 1e18;
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<ll> pre(n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    auto get_cost = [&](int l, int r, int m) -> ll
    {
        ll l1 = pre[m] - pre[l - 1], l2 = pre[r] - pre[m];
        ll logv = ((l1 + l2) > 0) ? (64 - __builtin_clzll(l1 + l2 - 1)) : 0;
        return min(l1, l2) * logv;
    };
    auto get_b = [&](int l, int r, int m) -> ll
    {
        ll l1 = pre[m] - pre[l - 1], l2 = pre[r] - pre[m];
        return abs(l1 - l2);
    };

    vector<vector<vector<PII>>> f(n + 1, vector<vector<PII>>(n + 1));

    for (int len = 2; len < n; len++)
    {
        for (int l = 1; l <= n - len + 1; l++)
        {
            int r = l + len - 1;
            for (int m = l; m < r; m++)
            {
                ll cc = get_cost(l, r, m), cl = 0;
                ll b = get_b(l, r, m);
                int lenl = m - l + 1;
                bool okl = 1;
                if (lenl > 1)
                {
                    if (f[l][m].empty())
                        okl = 0;
                    else
                    {
                        PII tmp = {b, inf};
                        auto p = upper_bound(f[l][m].begin(), f[l][m].end(), tmp) - 1 - f[l][m].begin();
                        if (p < 0)
                            okl = 0;
                        else
                            cl = f[l][m][p].second;
                    }
                }
                ll cr = 0;
                int lenr = r - m;
                bool okr = 1;
                if (lenr > 1)
                {
                    if (f[m + 1][r].empty())
                        okr = 0;
                    else
                    {
                        PII tmp = {b, inf};
                        auto p = upper_bound(f[m + 1][r].begin(), f[m + 1][r].end(), tmp) - 1 - f[m + 1][r].begin();
                        if (p < 0)
                            okr = 0;
                        else
                            cr = f[m + 1][r][p].second;
                    }
                }
                if (okl && okr)
                {
                    ll cost = cc + cl + cr;
                    f[l][r].push_back({b, cost});
                }
            }
            if (f[l][r].empty())
                continue;
            sort(f[l][r].begin(), f[l][r].end());
            ll minb = inf;
            for (int i = 0; i < f[l][r].size(); i++)
            {
                f[l][r][i].second = min(minb, f[l][r][i].second);
                minb = f[l][r][i].second;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        int l = 1, r = n, m = i;
        ll cc = get_cost(l, r, m), cl = 0;
        ll b = get_b(l, r, m);
        int lenl = m - l + 1;
        bool okl = 1;
        if (lenl > 1)
        {
            if (f[l][m].empty())
                okl = 0;
            else
            {
                PII tmp = {b, inf};
                auto p = upper_bound(f[l][m].begin(), f[l][m].end(), tmp) - 1 - f[l][m].begin();
                if (p < 0)
                    okl = 0;
                else
                    cl = f[l][m][p].second;
            }
        }
        ll cr = 0;
        int lenr = r - m;
        bool okr = 1;
        if (lenr > 1)
        {
            if (f[m + 1][r].empty())
                okr = 0;
            else
            {
                PII tmp = {b, inf};
                auto p = upper_bound(f[m + 1][r].begin(), f[m + 1][r].end(), tmp) - 1 - f[m + 1][r].begin();
                if (p < 0)
                    okr = 0;
                else
                    cr = f[m + 1][r][p].second;
            }
        }
        if (okl && okr)
        {
            ll cost = cc + cl + cr;
            cout << cost << ' ';
        }
        else
            cout << -1 << ' ';
    }
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