#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105909
const int N = 1e6;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector adj(n + 1, vector<int>());
    vector<int> fa(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int f;
        cin >> f;
        fa[i] = f;
        adj[f].push_back(i);
    }
    vector<int> nxt(N + 1), dep(n + 1);
    vector jp(n + 1, vector<int>(22));
    dep[0] = -1;
    auto dfs = [&](auto &&self, int u) -> void
    {
        dep[u] = dep[fa[u]] + 1;
        int pre = nxt[a[u]];
        nxt[a[u]] = u;
        jp[u][0] = nxt[a[u] + 1];
        for (int i = 1; i < 22; i++)
        {
            jp[u][i] = jp[jp[u][i - 1]][i - 1];
        }
        for (auto v : adj[u])
        {
            self(self, v);
        }
        nxt[a[u]] = pre;
    };
    dfs(dfs, 1);
    int q;
    cin >> q;
    auto query = [&](int s, int t) -> int
    {
        int u = s;
        int res = 1;
        for (int i = 21; i >= 0; i--)
        {
            if (dep[jp[u][i]] >= dep[t])
            {
                res += (1LL << i);
                u = jp[u][i];
            }
        }
        return res;
    };
    while (q--)
    {
        int s, t;
        cin >> s >> t;
        cout << query(s, t) << '\n';
    }
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