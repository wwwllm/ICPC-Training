#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
struct Info
{
    int sum;
    Info() : sum() {};
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
    void modify(int p, int l, int r, int x, const Info &v)
    {
        if (r - l == 1)
        {
            info[p].sum += v.sum;
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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<int> pre(n + 1);
    vector<int> b;
    b.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i] * (i & 1 ? 1 : -1);
        b.push_back(pre[i]);
    }
    ranges::sort(b);
    b.erase(unique(b.begin(), b.end()), b.end());
    auto find = [&](int x) -> int
    {
        return ranges::lower_bound(b, x) - b.begin();
    };
    int m = b.size();
    SegTree odd(m), even(m);
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i & 1)
        {
            odd.modify(find(pre[i]), 1);
            ans += even.query(0, find(pre[i])).sum;
        }
        else
        {
            even.modify(find(pre[i]), 1);
            ans += odd.query(find(pre[i]) + 1, m + 1).sum;
        }
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