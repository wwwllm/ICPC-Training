#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> f, siz;
    int cnt;
    vector<pair<int, int>> st; // 记录历史操作的栈

    DSU() {}
    DSU(int n) { init(n); }

    void init(int n)
    {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        cnt = n;
        st.clear();
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

        st.push_back({x, y}); // 记录谁成为了谁的父亲
        siz[x] += siz[y];
        cnt--;
        f[y] = x;
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
            auto [x, y] = st.back();
            st.pop_back();
            f[y] = y;         // 恢复父节点指向自己
            siz[x] -= siz[y]; // 恢复连通块大小
            cnt++;            // 恢复连通块数量
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
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    SegTree T(k);
    for (int i = 1; i <= m; i++)
    {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        T.modify(l, r, {u, v});
    }
    DSU dsu(2 * n + 1);

    auto dfs = [&](auto &&self, int p, int l, int r, bool ok) -> void
    {
        int cur = dsu.time();
        if (ok)
        {
            for (auto e : T.info[p])
            {
                auto [u, v] = e.e;
                if (dsu.find(u) == dsu.find(v))
                {
                    ok = 0;
                    break;
                }
                dsu.merge(u, v + n);
                dsu.merge(v, u + n);
            }
        }
        if (r - l == 1)
        {
            cout << (ok ? "Yes\n" : "No\n");
        }
        else
        {
            int mid = l + r >> 1;
            self(self, p << 1, l, mid, ok);
            self(self, p << 1 | 1, mid, r, ok);
        }
        dsu.roll_back(cur);
    };
    dfs(dfs, 1, 0, k, 1);
}
signed main()
{
    solve();
    return 0;
}