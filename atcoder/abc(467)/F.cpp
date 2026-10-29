#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 4e18;
struct Info
{
    int sum, max;
    Info() : sum(0), max(-inf) {};
    Info(int val, int max = -inf) : sum(val), max(max) {};
    Info operator+(const Info &other) const
    {
        Info res;
        res.sum = sum + other.sum;
        res.max = std::max(max, sum + other.max);
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
    vector<int> a(n + 1), b(n + 1);
    vector<int> value;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        value.push_back(b[i]);
    }
    vector<array<int, 3>> Q;
    for (int i = 0; i < q; i++)
    {
        int op, val, pos;
        cin >> op >> pos >> val;
        Q.push_back({op, pos, val});
        if (op == 2)
            value.push_back(val);
    }
    ranges::sort(value, greater<int>());
    value.erase(unique(value.begin(), value.end()), value.end());
    auto find = [&](int x)
    {
        return ranges::lower_bound(value, x, greater<int>()) - value.begin();
    };
    int m = value.size();
    SegTree t(m);
    vector<int> suma(m + 1);
    for (int i = 1; i <= n; i++)
    {
        suma[find(b[i])] += a[i];
    }
    for (int i = 0; i < m; i++)
    {
        if (suma[i] != 0)
            t.modify(i, Info(suma[i], suma[i] + value[i]));
        else
            t.modify(i, Info());
    }
    for (int i = 0; i < q; i++)
    {
        auto [op, pos, val] = Q[i];
        if (op == 1)
        {
            int idx = find(b[pos]);
            suma[idx] += val - a[pos];
            a[pos] = val;
            t.modify(idx, Info(suma[idx], suma[idx] + b[pos]));
            cout << t.query(0, m).max << '\n';
        }
        else
        {
            int idx = find(b[pos]);
            suma[idx] -= a[pos];
            if (suma[idx] != 0)
                t.modify(idx, Info(suma[idx], suma[idx] + b[pos]));
            else
                t.modify(idx, Info(suma[idx]));
            b[pos] = val;
            idx = find(b[pos]);
            suma[idx] += a[pos];
            t.modify(idx, Info(suma[idx], suma[idx] + b[pos]));
            cout << t.query(0, m).max << '\n';
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