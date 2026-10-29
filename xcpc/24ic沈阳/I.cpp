#include <bits/stdc++.h>
#define int long long
using namespace std;

struct DSU
{
    int n;
    vector<int> fa;
    DSU(int n) : n(n)
    {
        fa.resize(n);
        ranges::iota(fa, 0);
    }
    int find(int x)
    {
        return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
    }
    int merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return 0;
        fa[y] = x;
        return 1;
    }
};
void solve()
{
    int n;
    cin >> n;
    int N = 1LL << (n + 1);
    vector<int> a(N);
    for (int i = 2; i < N; i++)
        cin >> a[i];
    int ans = N;
    vector<int> dist(N), dep(N);
    for (int i = 2; i < N; i++)
    {
        dist[i] = dist[i >> 1] + a[i];
        dep[i] = dep[i >> 1] + 1;
    }
    vector<int> cut(N), cnt(n + 1);
    auto check = [&]() -> bool
    {
        int sum = 0;
        for (int d = n; d >= 1; d--)
        {
            sum += cnt[d];
            if (sum > n - d + 1)
            {
                return 0;
            }
        }
        return 1;
    };
    auto LCA = [&](int x, int y) -> int
    {
        while (x != y)
        {
            x >>= 1;
            y >>= 1;
        }
        return x;
    };
    auto find = [&]() -> array<int, 3>
    {
        DSU dsu(N);
        for (int i = 2; i < N; i++)
        {
            if (!cut[i])
                dsu.merge(i >> 1, i);
        }
        map<array<int, 2>, vector<int>> mp;
        int L = 1 << n, R = 1 << (n + 1);
        for (int u = L; u < R; u++)
        {
            mp[{dsu.find(u), dist[u]}].push_back(u);
        }
        array<int, 3> res = {-1, 1, -1};
        for (auto [x, p] : mp)
        {
            if (p.size() == 1)
                continue;
            for (int i = 1; i < p.size(); i++)
            {
                int u = p[i], v = p[i - 1];
                int lca = LCA(u, v);
                if (res[2] == -1 || dep[lca] > dep[res[2]])
                {
                    res = {u, v, lca};
                }
            }
        }
        return res;
    };
    auto find_sub = [&](int x, int r) -> int
    {
        while ((x >> 1) != r)
        {
            x >>= 1;
        }
        return x;
    };
    auto dfs = [&](auto &&self, int cur) -> void
    {
        if (cur > ans)
            return;
        auto [x, y, r] = find();
        if (x == -1)
        {
            ans = min(ans, cur);
            return;
        }
        int u = find_sub(x, r), v = find_sub(y, r);
        for (auto p : {u, v})
        {
            cut[p] = 1;
            cnt[dep[p]]++;
            if (check())
                self(self, cur + 1);
            cnt[dep[p]]--;
            cut[p] = 0;
        }
    };
    dfs(dfs, 0);
    cout << (ans == N ? -1 : ans) << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}