#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 0x3f3f3f3f3f;
struct dsu
{
    vector<int> a, mi;
    dsu(int n) : a(n, 0), mi(n, INF)
    {
        iota(a.begin(), a.end(), 0);
    }
    int find(int x)
    {
        if (a[x] == x)
            return x;
        return a[x] = find(a[x]);
    }
    void join(int u, int v, int w)
    {
        int fu = find(u), fv = find(v);
        if (fu != fv)
            a[fu] = fv, mi[fv] = min({w, mi[fu], mi[fv]});
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> e(m);
    for (auto &[w, u, v] : e)
    {
        cin >> u >> v >> w;
    }
    sort(e.begin(), e.end());
    dsu f(n + 1);
    int ans=INF;
    for (auto [w, u, v] : e)
    {
        f.join(u,v,w);
        if(f.find(1)==f.find(n)){
            ans = min(ans, w + f.mi[f.find(1)]);
        }
    }
    cout << ans << '\n';
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