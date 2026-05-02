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
    vector<int> rep;
    vector<array<int, 4>> st; // 记录历史操作的栈
    DSU *dsu;
    RollbackDSU() {}
    RollbackDSU(int n, DSU *dsu)
    {
        init(n);
        this->dsu = dsu;
    }

    void init(int n)
    {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        cnt = n;
        rep.assign(n, 0);
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

    bool merge(int x, int y, int cost)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return 0;

        // 启发式合并：小树合入大树，保证树高 O(log n)
        if (siz[x] < siz[y])
            swap(x, y);
        if (rep[x] && rep[y])
            dsu->merge(rep[x], rep[y], cost);

        st.push_back({y, x, siz[x], rep[x]}); // 记录谁成为了谁的父亲
        siz[x] += siz[y];
        cnt--;
        f[y] = x;
        if (!rep[x])
            rep[x] = rep[y];
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
            auto a = st.back();
            st.pop_back();
            int ch = a[0], fa = a[1], sz = a[2], re = a[3];
            f[ch] = ch;
            siz[fa] = sz;
            rep[fa] = re;
            cnt++;
        }
    }
};
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    DSU dsu(q + 1);
    vector e(m + 1, vector<array<int, 2>>());
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[w].push_back({u, v});
    }
    RollbackDSU DSU(n + 1, &dsu);
    vector<int> vis(n + 1);
    for (int i = 1; i <= q; i++)
    {
        int c;
        cin >> c;
        if (!vis[c])
        {
            vis[c] = i;
            DSU.rep[c] = i;
        }
        else
            dsu.merge(vis[c], i, 0);
    }
    auto add = [&](int l, int r, int cost)
    {
        if (dsu.count() == 2)
            return;
        for (int w = l; w < r; w++)
        {
            for (auto [u, v] : e[w])
            {
                DSU.merge(u, v, cost);
                if (dsu.count() == 2)
                    return;
            }
        }
    };
    auto dfs = [&](auto &&self, int l, int r) -> void
    {
        if (dsu.cnt == 2 || r - l == 1)
            return;
        int mid = l + r >> 1;

        int ti = DSU.time();
        add(mid, r, l);
        self(self, l, mid);
        DSU.roll_back(ti);
        ti = DSU.time();
        add(l, mid, mid);
        self(self, mid, r);
        DSU.roll_back(ti);
    };
    dfs(dfs, 0, m + 1);
    if (dsu.count() == 2)
    {
        cout << dsu.ans << '\n';
    }
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