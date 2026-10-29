#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
struct Info
{
    int sum;
    int size;
    Info() : sum(0), size(0) {};
    Info(int value, int cnt) : sum(value), size(cnt) {};
    Info operator+(const Info &other) const
    {
        Info res;
        res.sum = sum + other.sum;
        res.size = size + other.size;
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
            info[p] = info[p] + v;
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
    vector<int> a(n);
    vector<int> b;
    for (int i = 0; i < n; i++)
        cin >> a[i], b.push_back(a[i]);
    vector<array<int, 2>> Q(q);
    for (int i = 0; i < q; i++)
    {
        cin >> Q[i][0] >> Q[i][1];
        Q[i][0]--;
        b.push_back(Q[i][1]);
    }
    ranges::sort(b);
    b.erase(unique(b.begin(), b.end()), b.end());
    auto find = [&](int x)
    { return ranges::lower_bound(b, x) - b.begin(); };
    int m = b.size();
    SegTree t(m);
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        int pos = find(a[i]);
        t.modify(pos, {a[i], 1});
        if (a[i] > 0)
            r++;
    }
    auto calc = [&]()
    {
        int l = -1, r = m;
        while (l + 1 != r)
        {
            int mid = l + r >> 1;
            if (t.query(0, mid + 1).sum > 0)
                r = mid;
            else
                l = mid;
        }
        if (r == m)
            return 0LL;
        int sum = t.query(0, r).sum;
        int cnt = -sum / b[r];
        return t.query(r, m).size - cnt;
    };
    for (auto [pos, val] : Q)
    {
        if (a[pos] > 0)
            r--;
        t.modify(find(a[pos]), {-a[pos], -1});
        a[pos] = val;
        if (a[pos] > 0)
            r++;
        t.modify(find(a[pos]), {a[pos], 1});
        int l = calc();
        cout << r - l + 1 << '\n';
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