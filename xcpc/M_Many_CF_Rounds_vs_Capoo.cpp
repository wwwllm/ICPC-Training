#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/106380
const int inf = 2e18;
struct Info
{
    int sum;
    Info() : sum(0) {};
    Info(int value) : sum(value) {};
    Info operator+(const Info &other) const
    {
        Info res;
        res.sum = sum + other.sum;
        return res;
    }
};
struct SegTree
{
    int n;
    vector<Info> info;
    SegTree(int _n) : n(_n), info(4 * n) {};
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
    int n;
    cin >> n;
    vector<array<int, 2>> a, b;
    vector<int> sep;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        sep.push_back(x);
        sep.push_back(y);
        if (x >= y)
            a.push_back({x, y});
        else
            b.push_back({x, y});
    }
    ranges::sort(b, [&](array<int, 2> &x, array<int, 2> &y)
                 { return x[1] < y[1]; });
    ranges::sort(a);
    n = a.size();
    int m = b.size();
    ranges::sort(sep);
    sep.erase(unique(sep.begin(), sep.end()), sep.end());
    int s = sep.size();
    auto find = [&](int x) -> int
    { return ranges::lower_bound(sep, x) - sep.begin(); };
    SegTree t(s + 1);
    vector<int> w(m);
    for (int i = 0, j = 0; i < m; i++)
    {
        while (j < n && a[j][0] < b[i][1])
        {
            t.modify(find(a[j++][1]), 1);
        }
        int c = t.query(find(b[i][0]) + 1, s + 1).sum;
        w[i] = 1 - c;
    }

    auto pre = [&](int x)
    {
        int l = -1, r = m;
        while (l + 1 != r)
        {
            int mid = l + r >> 1;
            if (b[mid][1] <= x)
                l = mid;
            else
                r = mid;
        }
        return l;
    };
    vector<int> dp(m, -inf);
    for (int i = 0; i < m; i++)
    {
        int p = pre(b[i][0]);
        int val = p == -1 ? 0 : dp[p];
        if (i == 0)
            dp[i] = max(0LL, val + w[i]);
        else
            dp[i] = max(dp[i - 1], val + w[i]);
    }
    cout << max(n, n + dp[m - 1]) << '\n';
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