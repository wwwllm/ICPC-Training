#include <bits/stdc++.h>
#define int long long
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
    vector<int> tag;
    vector<Info> info;
    SegTree(int _n) : n(_n), tag(4 * _n), info(4 * n) {};
    void pull(int p) // 更新上移
    {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    void add(int p, int v)
    {
        tag[p] += v;
        info[p].min += v;
    }
    void push(int p) // 懒标记下放
    {
        add(p << 1, tag[p]);
        add(p << 1 | 1, tag[p]);
        tag[p] = 0;
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
        push(p);
        return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid, r, x, y);
    };
    Info query(int x, int y)
    {
        return query(1, 0, n, x, y);
    };
    // 区间修改[x,y)
    void rangeAdd(int p, int l, int r, int x, int y, int v)
    {
        if (l >= y || r <= x)
            return;
        if (l >= x && r <= y)
        {
            return add(p, v);
        }
        int mid = l + r >> 1;
        push(p);
        rangeAdd(p << 1, l, mid, x, y, v);
        rangeAdd(p << 1 | 1, mid, r, x, y, v);
        pull(p);
    };
    void rangeAdd(int x, int y, int v)
    {
        rangeAdd(1, 0, n, x, y, v);
    }
    // 单点修改
    void modify(int p, int l, int r, int x, const Info &v)
    {
        if (r - l == 1)
        {
            info[p] = v;
            return;
        }
        int mid = l + r >> 1;
        push(p);
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
void solve()
{
    int n;
    cin >> n;
    SegTree t(n + 2);
    int cur = 0;
    for (int i = 0; i <= n + 1; i++)
    {
        t.modify(i, 0);
    }
    t.modify(0, -1);
    map<int, int> vis;
    int m = 0;
    for (int j = 0; j < n; j++)
    {
        int x;
        cin >> x;
        if (vis[x] || x > m)
        {
            int r = (x - 1) / 2;
            if (r >= 0)
                t.rangeAdd(0, r + 1, 1);
        }
        else
        {
            t.modify(x, inf);
            t.rangeAdd(0, x + 1, 1);
        }
        vis[x] = 1;
        while (1)
        {
            if (t.query(0, m + 1).min < 0)
                break;
            m++;
            t.rangeAdd(0, m + 1, -1);
            if (vis[m])
            {
                t.modify(m, inf);
                int r = (m - 1) / 2;
                if (r >= 0)
                    t.rangeAdd(0, r + 1, -1);
                t.rangeAdd(0, m + 1, 1);
            }
        }
        cout << m << ' ';
    }
    cout << '\n';
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