#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9, N = 2e5;
struct Info
{
    int G;
    Info() : G(0) {};
    Info(int value) : G(value) {};
    Info operator+(const Info &other) const
    {
        Info res;
        res.G = gcd(G, other.G);
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
vector<int> f(N + 1);
void init()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
        {
            f[j]++;
        }
    }
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    SegTree t(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i + 1])
            t.modify(i, i);
    }
    int g = t.query(0, n + 1).G;
    cout << (g == 0 ? n : f[g]) << '\n';
    while (q--)
    {
        int pos, v;
        cin >> pos >> v;
        a[pos] = v;
        if (pos < n && a[pos] > a[pos + 1])
            t.modify(pos, pos);
        else
            t.modify(pos, 0);
        if (pos > 1 && a[pos - 1] > a[pos])
            t.modify(pos - 1, pos - 1);
        else
            t.modify(pos - 1, 0);
        g = t.query(0, n + 1).G;
        cout << (g == 0 ? n : f[g]) << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}