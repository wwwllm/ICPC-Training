#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
struct Info
{
    int sum, max;
    Info() : sum(), max(-inf) {};
    Info(int value) : sum(value), max(value) {};
};
struct SegTree
{
    int n;
    vector<Info> info;
    SegTree(int _n) : n(_n), info(4 * _n) {};
    int calc(int p, int l, int r, int val)
    {
        if (r - l == 1)
            return std::max(val, info[p].max);
        int mid = l + r >> 1;
        if (val >= info[p << 1].max)
        {
            int lres = val * (mid - l);
            return lres + calc(p << 1 | 1, mid, r, val);
        }
        else
        {
            int lres = calc(p << 1, l, mid, val);
            int rres = info[p].sum - info[p << 1].sum;
            return lres + rres;
        }
    }
    void pull(int p, int l, int r) // 更新上移
    {
        info[p].max = std::max(info[p << 1].max, info[p << 1 | 1].max);
        info[p].sum = info[p << 1].sum + calc(p << 1 | 1, l + r >> 1, r, info[p << 1].max);
    }
    // 区间查询[x,y)
    int query(int p, int l, int r, int x, int y, int &cur)
    {
        if (l >= y || r <= x)
            return {};
        if (l >= x && r <= y)
        {
            int res = calc(p, l, r, cur);
            cur = max(info[p].max, cur);
            return res;
        }
        int res = 0;
        int mid = l + r >> 1;
        if (x < mid)
            res += query(p << 1, l, mid, x, y, cur);

        if (y > mid)
            res += query(p << 1 | 1, mid, r, x, y, cur);

        return res;
    };
    int query(int x, int y)
    {
        int cur = -inf;
        return query(1, 0, n, x, y, cur);
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
        pull(p, l, r);
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
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], sum += a[i];
    SegTree pre(n), suf(n);
    for (int i = 0; i < n; i++)
    {
        pre.modify(i, a[i]);
        suf.modify(n - i - 1, a[i]);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int pos, val;
        cin >> pos >> val;
        sum += val;
        pos--;
        a[pos] += val;
        pre.modify(pos, a[pos]);
        suf.modify(n - 1 - pos, a[pos]);
        auto info1 = pre.info[1];
        auto info2 = suf.info[1];
        int res = info1.sum + info2.sum - n * info1.max;
        cout << res - sum << '\n';
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