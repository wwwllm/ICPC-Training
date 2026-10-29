#pragma GCC optimize("O2")
#include <bits/stdc++.h>
// #define int long long
using namespace std;

using i64 = long long;
const int inf = 0;
struct Info
{
    int max;
    Info() : max(-inf) {};
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
    void modify(int x, int v)
    {
        modify(1, 0, n, x, Info(v));
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<i64> a(n + 1);
    vector<i64> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i], b.push_back(a[i]);
    }
    ranges::sort(b);
    b.erase(unique(b.begin(), b.end()), b.end());
    int m = b.size();
    auto find = [&](i64 x) -> int
    {
        return ranges::lower_bound(b, x) - b.begin();
    };
    vector dp(n + 1, vector<int>(62));
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = i;
    }
    vector<int> pl(n + 1), pr(n + 1), idx(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pl[i] = ranges::lower_bound(b, (a[i] + 2) / 3) - b.begin();
        pr[i] = ranges::upper_bound(b, a[i] / 2) - b.begin();
        idx[i] = find(a[i]);
    }
    for (int len = 2; len < 62; len++)
    {
        SegTree t(m);
        for (int i = 1; i <= n; i++)
        {
            int l = pl[i];
            int r = pr[i];
            int pos = t.query(l, r).max;
            dp[i][len] = pos;
            t.modify(idx[i], dp[i][len - 1]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int len = 1; len < 62; len++)
        {
            dp[i][len] = max(dp[i][len], dp[i - 1][len]);
        }
    }
    auto calc = [&](int L, int R)
    {
        int l = 0, r = 62;
        while (l + 1 != r)
        {
            int mid = l + r >> 1;
            int pos = dp[R][mid];
            if (pos >= L)
                l = mid;
            else
                r = mid;
        }
        return l;
    };
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << calc(l, r) << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}