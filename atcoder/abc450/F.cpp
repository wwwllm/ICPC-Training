#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18, mod = 998244353;
struct Info
{
    int sum;
    Info() : sum(0) {};
    Info(int value) : sum(value) {};
    Info operator+(const Info &other) const
    {
        Info res;
        res.sum = (sum + other.sum) % mod;
        return res;
    }
};
struct SegTree
{
    int n;
    vector<int> tag;
    vector<Info> info;
    SegTree(int _n) : n(_n), tag(4 * _n, 1), info(4 * n) {};
    void pull(int p) // 更新上移
    {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    void add(int p, int v)
    {
        tag[p] = tag[p] * v % mod;
        info[p].sum = info[p].sum * v % mod;
    }
    void push(int p) // 懒标记下放
    {
        add(p << 1, tag[p]);
        add(p << 1 | 1, tag[p]);
        tag[p] = 1;
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
    void rangeMul(int p, int l, int r, int x, int y, int v)
    {
        if (l >= y || r <= x)
            return;
        if (l >= x && r <= y)
        {
            return add(p, v);
        }
        int mid = l + r >> 1;
        push(p);
        rangeMul(p << 1, l, mid, x, y, v);
        rangeMul(p << 1 | 1, mid, r, x, y, v);
        pull(p);
    };
    void rangeMul(int x, int y, int v)
    {
        rangeMul(1, 0, n, x, y, v);
    }
    // 单点加
    void modify(int p, int l, int r, int x, const Info &v)
    {
        if (r - l == 1)
        {
            info[p] = info[p] + v;
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
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> a(m);
    for (auto &[l, r] : a)
        cin >> l >> r;
    ranges::sort(a);
    SegTree T(n + 1);
    T.modify(1, 1);
    for (auto [l, r] : a)
    {
        auto info = T.query(l, r + 1);
        T.modify(r, info.sum);
        T.rangeMul(1, l, 2);
        T.rangeMul(r + 1, n + 1, 2);
    }
    cout << (T.query(n, n + 1).sum) << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}