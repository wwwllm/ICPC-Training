#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    vector<int> p(n + 1);
    vector<array<int, 3>> op(q + 1);
    iota(p.begin(), p.end(), 0);
    vector<int> u(n + q + 1), v(n + q + 1);
    for (int i = 1; i <= q; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        op[i] = {x, y, z};
        u[n + i] = p[x];
        v[n + i] = p[y];
        p[z] = n + i;
    }
    vector<int> ans(n + q + 1);
    for (int i = 1; i <= n; i++)
    {
        ans[p[i]] = b[i];
    }
    for (int i = n + q; i > n; i--)
    {
        ans[u[i]] = max(ans[u[i]], ans[i]);
        ans[v[i]] = max(ans[v[i]], ans[i]);
    }
    ans.resize(n + 1);
    auto a = ans;
    for (int i = 1; i <= q; i++)
    {
        auto [x, y, z] = op[i];
        a[z] = min(a[x], a[y]);
    }
    if (a != b)
    {
        cout << -1 << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " \n"[i == n];
    }
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