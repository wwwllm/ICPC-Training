#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
struct DSU
{
    vector<int> f, siz;
    int cnt;
    int ans;

    DSU() {}
    DSU(int n) { init(n); }

    void init(int n)
    {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        cnt = n;
        ans = 0;
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool merge(int x, int y, int cost)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return 0;
        siz[x] += siz[y];
        cnt--;
        f[y] = x;
        ans += cost;
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
struct RollbackDSU
{
    vector<int> f, siz;
    int cnt;
    vector<array<int, 4>> st; // 记录历史操作的栈
    vector<int> vis;

    RollbackDSU() {}
    RollbackDSU(int n) { init(n); }

    void init(int n)
    {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        cnt = n;
        st.clear();
        vis.assign(n, 0);
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x];
        }
        return x;
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return 0;

        // 启发式合并：小树合入大树，保证树高 O(log n)
        if (siz[x] < siz[y])
            swap(x, y);

        st.push_back({y, x, siz[x], vis[x]}); // 记录谁成为了谁的父亲
        siz[x] += siz[y];
        cnt--;
        f[y] = x;
        if (vis[x] == 0)
            vis[x] = vis[y];
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

    // 获取当前时间戳
    int time()
    {
        return st.size();
    }

    // 回滚至指定时间戳 t
    void roll_back(int t)
    {
        while (st.size() > t)
        {
            auto [ch, fa, sz, re] = st.back();
            st.pop_back();
            f[ch] = ch;
            siz[fa] = sz;
            vis[fa] = re;
            cnt++;
        }
    }
};
struct Info
{
    array<int, 2> e;
    Info() {};
    Info(int u, int v) { e = {u, v}; };
    Info(array<int, 2> e) : e(e) {};
};
struct SegTree
{
    int n;
    vector<vector<Info>> info;

    SegTree(int n) : n(n), info(4 * n) {};
    void modify(int p, int l, int r, int ql, int qr, Info e)
    {
        if (ql <= l && r <= qr)
        {
            info[p].push_back(e);
            return;
        }
        if (ql >= r || qr <= l)
            return;
        int mid = l + r >> 1;
        if (ql < mid)
            modify(p << 1, l, mid, ql, qr, e);
        if (qr > mid)
            modify(p << 1 | 1, mid, r, ql, qr, e);
    }
    void modify(int l, int r, array<int, 2> e)
    {
        modify(1, 0, n, l, r, e);
    }
};
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    SegTree t(m + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (w > 0)
            t.modify(0, w, {u, v});
        if (w < m + 1)
            t.modify(w + 1, m + 1, {u, v});
    }
    DSU dsu(q + 1);
    RollbackDSU DSU(n + 1);
    auto &vis = DSU.vis;
    vector<int> p;
    for (int i = 1; i <= q; i++)
    {
        int c;
        cin >> c;
        if (!vis[c])
        {
            vis[c] = i;
            p.push_back(c);
        }
        else
            dsu.merge(vis[c], i, 0);
    }
    auto dfs = [&](auto &&self, int idx, int l, int r) -> void
    {
        if (dsu.count() == 2)
            return;
        int ti = DSU.time();
        for (auto e : t.info[idx])
        {
            DSU.merge(e.e[0], e.e[1]);
        }
        if (r - l == 1)
        {
            ranges::sort(p, [&](int a, int b)
                         { return DSU.find(a) < DSU.find(b); });
            vector<int> np;
            for (int i = 0; i < p.size(); i++)
            {
                if (i == 0 || DSU.find(p[i]) != DSU.find(p[i - 1]))
                    np.push_back(p[i]);
                else if (vis[p[i]] != 0 && vis[p[i - 1]] != 0)
                    dsu.merge(vis[p[i]], vis[p[i - 1]], l);
            }
            p = np;
        }
        else
        {
            int mid = l + r >> 1;
            self(self, idx << 1, l, mid);
            self(self, idx << 1 | 1, mid, r);
        }
        DSU.roll_back(ti);
    };
    dfs(dfs, 1, 0, m + 1);
    if (dsu.count() == 2)
        cout << dsu.ans << '\n';
    else
        cout << -1 << '\n';
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