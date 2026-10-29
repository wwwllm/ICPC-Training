#include <bits/stdc++.h>
#define int long long
using namespace std;

struct DSU
{
    vector<int> f, siz, val;
    int cnt;

    DSU() {}
    DSU(int n) { init(n); }

    void init(int n)
    {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        val.assign(n, 0);
        cnt = n;
    }

    int find(int x)
    {
        vector<int> path;
        int root = x;
        while (root != f[root])
        {
            path.push_back(root);
            root = f[root];
        }
        int cur = 0;
        ranges::reverse(path);
        for (auto u : path)
        {
            cur = max(cur, val[u]);
            f[u] = root;
            val[u] = cur;
        }
        return root;
    }

    bool merge(int x, int y, int v) // y->x
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return 0;
        f[y] = x;
        siz[x] += siz[y];
        val[y] = v;
        return 1;
    }

    int esize(int x)
    {
        return siz[find(x)];
    }

    int count()
    {
        return cnt;
    }
};
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector g(n + 1, vector<int>(m + 1));
    int cur = 0;
    int pre = 0;
    auto get_pos = [&](int x, int y) -> int
    {
        return (x - 1) * m + y;
    };
    auto get_point = [&](int &x, int &y)
    {
        x ^= pre, y ^= pre;
    };
    DSU dsu(n * m + 1);
    vector<int> val(n * m + 1);
    vector<array<int, 2>> walk = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y, w;
            cin >> x >> y >> w;
            get_point(x, y);
            g[x][y] = w;
            int u = get_pos(x, y);
            vector<int> tmp;
            for (auto [dx, dy] : walk)
            {
                int xx = x + dx, yy = y + dy;
                if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && g[xx][yy] != 0)
                {
                    int v = get_pos(xx, yy);
                    tmp.push_back(dsu.find(v));
                }
            }
            ranges::sort(tmp);
            tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
            for (auto v : tmp)
            {
                int val = max(0ll, w - dsu.esize(v) + 1);
                dsu.merge(u, v, val);
            }
            pre = dsu.esize(u) - 1;
        }
        else
        {
            int x, y;
            cin >> x >> y;
            get_point(x, y);
            int u = get_pos(x, y);
            int fu = dsu.find(u);
            pre = max(0LL, dsu.val[u] - g[x][y]);
        }
        cout << pre << '\n';
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