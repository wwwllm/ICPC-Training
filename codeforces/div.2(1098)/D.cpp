#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
struct Info
{
    int cnt;
    Info() : cnt(0) {};
    Info(int value) : cnt(value) {};
    Info operator+(const Info &other) const
    {
        return Info(cnt + other.cnt);
    }
};
struct ValueSegTree
{
    int n;
    vector<int> tag;
    vector<Info> info;
    ValueSegTree(int _n) : n(_n), tag(4 * _n), info(4 * n) {};
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
    int query(int x, int y)
    {
        return query(1, 0, n, x, y).cnt;
    };

    // 单点修改:在x上加v
    void modify(int p, int l, int r, int x, int v)
    {
        if (r - l == 1)
        {
            info[p].cnt = v;
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
        modify(1, 0, n, x, v);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    ValueSegTree t(n + 1);
    vector<int> may(n + 1), miy(n + 1, n + 1);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = x;
        t.modify(y, 1);
        miy[x] = min(miy[x], y);
        may[x] = max(may[x], y - 1);
    }
    ranges::sort(a);
    a.erase(unique(a.begin(), a.end()), a.end());
    vector<int> lmin(n + 1, n + 1), lmax(n + 1, 0), rmin(n + 2, n + 1), rmax(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        lmin[i] = min(lmin[i - 1], miy[i]);
        lmax[i] = max(lmax[i - 1], may[i]);
    }
    for (int i = n; i >= 1; i--)
    {
        rmin[i] = min(rmin[i + 1], miy[i]);
        rmax[i] = max(rmax[i + 1], may[i]);
    }
    int ans = 0;
    for (int i = 0; i < a.size() - 1; i++)
    {
        int x = a[i];
        int l = max(lmin[x], rmin[x + 1]), r = min(lmax[x], rmax[x + 1]);
        if (l <= r)
            ans += t.query(l, r + 1);
    }
    cout << ans << '\n';
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