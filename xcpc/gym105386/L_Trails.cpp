#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105386/problem/L
const int inf = 1e9;
struct Info
{
    int max;
    Info() : max(0) {};
    Info(int value) : max(value) {};
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
    void modify(int x, int v)
    {
        modify(1, 0, n, x, Info(v));
    }
};
void solve()
{
    int n, p, q;
    cin >> n >> p >> q;
    vector<array<int, 2>> a(n);
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
        b.push_back(a[i][0]);
        b.push_back(a[i][1]);
    }
    ranges::sort(b);
    b.erase(unique(b.begin(), b.end()), b.end());
    auto find = [&](int x)
    { return ranges::lower_bound(b, x) - b.begin(); };

    ranges::sort(a, [&](array<int, 2> &a, array<int, 2> &b)
                 { return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; });
    vector<int> cnt(n);
    int m = b.size();
    SegTree t(m);
    for (int i = 0; i < n; i++)
    {
        int tmp = t.query(0, find(a[i][1])).max;
        cnt[i] = tmp + 1;
        t.modify(find(a[i][1]), cnt[i]);
    }
    vector g(n + 1, vector<array<int, 2>>());
    for (int i = 0; i < n; i++)
    {
        if (a[i][0] < p && a[i][1] < q)
        {
            g[cnt[i]].push_back({a[i][0] + 1, a[i][1] + 1});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        g[i].push_back({0, q + 1});
        ranges::sort(g[i], [&](array<int, 2> &a, array<int, 2> &b)
                     { return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; });
    }
    int ans = (p + 1) * (q + 1) * (p + q) / 2;
    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() == 1)
            continue;
        for (int j = 1; j < g[i].size(); j++)
        {
            ans -= (g[i][j - 1][1] - g[i][j][1]) * (p + 1 - g[i][j][0]);
        }
    }
    cout << ans << '\n';
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