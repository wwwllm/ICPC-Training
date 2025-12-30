#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2060/E
int find(int x, vector<int> &a)
{
    if (a[x] == x)
        return x;
    return a[x] = find(a[x], a);
}
void solve()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<int> bcjg(n + 1), bcjf(n + 1);
    iota(bcjg.begin(), bcjg.end(), 0);
    iota(bcjf.begin(), bcjf.end(), 0);
    vector<array<int, 2>> f(m1 + 1);
    for (int i = 1; i <= m1; i++)
    {
        int u, v;
        cin >> u >> v;
        f[i] = {u, v};
    }
    for (int i = 1; i <= m2; i++)
    {
        int u, v;
        cin >> u >> v;
        int fu = find(u, bcjg), fv = find(v, bcjg);
        if (fu != fv)
            bcjg[fu] = fv;
    }
    int res = 0;
    for (int i = 1; i <= m1; i++)
    {
        auto [u, v] = f[i];
        int fu = find(u, bcjg), fv = find(v, bcjg);
        if (fu == fv)
            bcjf[find(u, bcjf)] = find(v, bcjf);
        else
            res++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (bcjf[i] == i)
            ans++;
        if (bcjg[i] == i)
            ans--;
    }
    cout << ans + res << '\n';
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