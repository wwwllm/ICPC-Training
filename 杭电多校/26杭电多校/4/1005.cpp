#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
struct Info
{
    int min;
    Info() : min(inf) {};
    Info(int value) : min(value) {};
    Info operator+(const Info &other) const
    {
        Info res;
        res.min = std::min(min, other.min);
        return res;
    }
};
struct SegTree
{
    int n;
    vector<Info> info;
    SegTree(int _n) : n(_n), info(4 * _n) {};
    void pull(int p) // 更新上移
    {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    // 区间查询[x,y)
    Info query(int p, int l, int r, int x, int y)
    {
        if (l >= y || r <= x)
            return {};
        if (l >= x && r <= y)
        {
            return info[p];
        }
        int mid = l + r >> 1;
        return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid, r, x, y);
    };
    Info query(int x, int y)
    {
        return query(1, 0, n, x, y);
    };
    // 单点修改
    void modify(int p, int l, int r, int x, const Info &v)
    {
        if (r - l == 1)
        {
            info[p] = v;
            return;
        }
        int mid = l + r >> 1;
        if (x < mid)
        {
            modify(p << 1, l, mid, x, v);
        }
        else
        {
            modify(p << 1 | 1, mid, r, x, v);
        }
        pull(p);
    }
    void modify(int x, int v)
    {
        modify(1, 0, n, x, Info(v));
    }
};
struct ST
{
    int bit = 20;
    int n;
    vector<vector<int>> up, mx;
    vector<int> fa, dep, val;
    ST(vector<int> &fa, vector<int> &dep, vector<int> &val) : fa(fa), dep(dep), val(val), n(fa.size())
    {
        up.assign(20, vector<int>(n));
        mx.assign(20, vector<int>(n));
        work();
    };
    void work()
    {
        up[0] = fa;
        mx[0] = val;
        for (int i = 1; i < bit; i++)
        {
            for (int u = 0; u < n; u++)
            {
                up[i][u] = up[i - 1][up[i - 1][u]];
                mx[i][u] = max(mx[i - 1][u], mx[i - 1][up[i - 1][u]]);
            }
        }
    }
    int query(int x, int y)
    {
        int len = dep[x] - dep[y] + 1;
        int ans = 0;
        for (int i = bit - 1; i >= 0; i--)
        {
            if (len >> i & 1)
            {
                ans = max(ans, mx[i][x]);
                x = up[i][x];
            }
        }
        return ans;
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), pos(n + 1);
    SegTree t(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
        t.modify(i, a[i]);
    }
    auto find = [&](int l, int r)
    {
        return pos[t.query(l, r + 1).min];
    };
    vector<int> ls(n + 1), rs(n + 1);
    vector<int> stk;
    for (int i = 1; i <= n; i++)
    {
        int lson = 0;
        while (stk.size() && a[stk.back()] > a[i])
        {
            lson = stk.back();
            stk.pop_back();
        }
        if (stk.size())
        {
            rs[stk.back()] = i;
        }
        if (lson)
            ls[i] = lson;
        stk.push_back(i);
    }
    vector<int> dep(n + 1);
    for (int u = n; u >= 1; u--)
    {
        int i = pos[u];
        dep[i] = max(dep[ls[i]], dep[rs[i]]) + 1;
    }
    vector<int> nxt(n + 2, n + 1), depr(n + 2);
    stk.clear();
    for (int i = n; i >= 1; i--)
    {
        while (stk.size() && a[stk.back()] > a[i])
        {
            stk.pop_back();
        }
        if (stk.size())
        {
            nxt[i] = stk.back();
        }
        stk.push_back(i);
    }
    for (int i = n; i >= 1; i--)
    {
        depr[i] = max(depr[nxt[i]] + 1, depr[i]);
    }
    vector<int> pre(n + 1);
    vector<int> depl(n + 1);
    stk.clear();
    for (int i = 1; i <= n; i++)
    {
        while (stk.size() && a[stk.back()] > a[i])
        {
            stk.pop_back();
        }
        if (stk.size())
        {
            pre[i] = stk.back();
        }
        stk.push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        depl[i] = max(depl[pre[i]] + 1, depl[i]);
    }
    vector<int> vall(n + 1), valr(n + 2);
    for (int i = 1; i <= n; i++)
    {
        valr[i] = depr[i] + dep[rs[i]];
        vall[i] = depl[i] + dep[ls[i]];
    }
    ST L(nxt, depr, valr), R(pre, depl, vall);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int root = find(l, r);
        int resl = 0, resr = 0;
        if (l < root)
        {
            int lson = find(l, root - 1);
            resl = L.query(l, lson) - depr[lson] + 1;
        }
        if (r > root)
        {
            int rson = find(root + 1, r);
            resr = R.query(r, rson) - depl[rson] + 1;
        }
        cout << 1 + max(resr, resl) << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}