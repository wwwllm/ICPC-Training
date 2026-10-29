#include <bits/stdc++.h>
using namespace std;

const int inf = 0;
struct Info
{
    int max;
    Info() : max(0) {};
    Info(int pos) : max(pos) {};
    Info operator+(const Info &other) const
    {
        Info res;
        res.max = std::max(max, other.max);
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
    void modify(int x, Info v)
    {
        modify(1, 0, n, x, v);
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<SegTree> t(3, (n + 1));
    for (int i = 1; i <= n; i++)
    {
        t[a[i]].modify(i, Info(i));
    }
    vector<vector<int>> Q = {
        {0, 1, 2},
        {0, 1},
        {1, 2},
        {0, 2}};
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int pos, x;
            cin >> pos >> x;
            t[a[pos]].modify(pos, Info());
            a[pos] = x;
            t[a[pos]].modify(pos, Info(pos));
        }
        else
        {
            int l, r;
            cin >> l >> r;
            int res = 0;
            for (auto p : Q)
            {
                int pre = r;
                bool ok = 1;
                for (auto x : p)
                {
                    int p = t[x].query(0, pre + 1).max;
                    if (p < l)
                    {
                        ok = 0;
                        break;
                    }
                    pre = p;
                }
                if (ok)
                {
                    res = max(res, (int)p.size() - 1);
                    break;
                }
            }
            cout << res << '\n';
        }
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