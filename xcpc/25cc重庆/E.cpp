#include <bits/stdc++.h>

#define int long long
using namespace std;
const int inf = 1e9;
struct Info
{
    int sum;
    int size;
    Info() : sum(), size(0) {};
    Info(int value) : sum(value), size(1) {};
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
    void modify(int x, int v)
    {
        modify(1, 0, n, x, Info(v));
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    vector<int> b;
    for (int i = 0; i < n; i++)
        cin >> a[i][0], b.push_back(a[i][0]);
    for (int i = 0; i < n; i++)
        cin >> a[i][1];
    ranges::sort(a, [&](const auto &a, const auto &b)
                 { return a[1] > b[1]; });
    ranges::sort(b);
    b.erase(unique(b.begin(), b.end()), b.end());
    int m = b.size();
    auto find = [&](int x) -> int
    {
        return ranges::lower_bound(b, x) - b.begin();
    };
    SegTree t(m);
    auto calc = [&](int R) -> int
    {
        int l = -1, r = m;
        while (l + 1 != r)
        {
            int mid = l + r >> 1;
            auto info = t.query(0, mid + 1);
            int cost = info.sum, rr = R * info.size;
            if (rr >= cost)
                l = mid;
            else
                r = mid;
        }
        return t.query(0, l + 1).size;
    };
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        t.modify(find(a[i][0]), a[i][0]);
        ans = max(ans, calc(a[i][1]));
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