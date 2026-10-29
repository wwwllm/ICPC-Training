#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105909
const int inf = 1e18;
struct Info
{
    array<int, 3> sum;
    int size;
    Info() : sum({0, 0, 0}), size(0) {};
    Info(array<int, 3> val) : sum(val), size(1) {};
    Info operator+(const Info &other) const
    {
        Info res;
        for (int i = 0; i < 3; i++)
        {
            res.sum[i] = sum[i] + other.sum[i];
        }
        res.size = size + other.size;
        return res;
    }
};
struct SegTree
{
    int n;
    vector<array<int, 3>> tag;
    vector<Info> info;
    SegTree(int _n) : n(_n), tag(4 * _n), info(4 * n) {};
    void pull(int p) // 更新上移
    {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    void add(int p, array<int, 3> v)
    {
        for (int i = 0; i < 3; i++)
        {
            tag[p][i] += v[i];
            info[p].sum[i] += v[i] * info[p].size;
        }
    }
    void push(int p) // 懒标记下放
    {
        add(p << 1, tag[p]);
        add(p << 1 | 1, tag[p]);
        tag[p] = {0, 0, 0};
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
    void rangeAdd(int p, int l, int r, int x, int y, array<int, 3> v)
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
    void rangeAdd(int x, int y, array<int, 3> v)
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
    void modify(int x, array<int, 3> v)
    {
        modify(1, 0, n, x, Info(v));
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> R(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> R[i];
    SegTree t(n + 1);
    for (int i = 1; i <= n; i++)
    {
        t.modify(i, {0, 0, 0});
    }
    for (int i = 1; i <= n; i++)
    {
        int l = i;
        auto a = t.query(i, i + 1).sum;
        int res = a[0] * i * i + a[1] * i + a[2];
        res /= 2;
        cout << res << '\n';
        int r = min(n, i + R[i]);
        int len = r - i - 1;
        int mid = l + r >> 1;
        if (len)
        {
            t.rangeAdd(l + 1, mid + 1, {-3, 4 * i + 2 * r + 1, -i * (i + 2 * r + 1)});
            t.rangeAdd(mid + 1, r, {1, -(2 * r + 1), r + r * r});
        }
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