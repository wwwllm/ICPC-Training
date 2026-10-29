#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9, N = 1e5;
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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << "0\n";
        return;
    }
    vector<int> b(n + 1);
    for (int i = 2; i < n; i++)
    {
        b[i] = a[i - 1] + a[i + 1];
    }
    SegTree tb(2 * N + 1);
    int ans = 0;
    vector<int> ord;
    for (int i = 2; i < n; i++)
    {
        ord.push_back(i);
    }
    int m = ord.size();
    ranges::sort(ord, [&](int x, int y)
                 { return a[x] < a[y]; });
    for (int i = 0; i < m;)
    {
        int j = i;
        while (j < m && a[ord[i]] == a[ord[j]])
            j++;
        for (int k = i; k < j; k++)
        {
            ans += tb.query(0, b[ord[k]]).sum;
        }
        for (int k = i; k < j; k++)
        {
            tb.modify(b[ord[k]], 1);
        }
        i = j;
    }
    auto calc = [&](vector<int> &pos) -> int
    {
        int res = 0;
        for (auto i : pos)
        {
            if (i < 1 || i >= n)
                continue;
            res += (a[i] - a[i + 1]) * (a[i] - a[i + 1]);
        }
        return res;
    };
    for (int i = 2; i < n - 1; i++)
    {
        if ((a[i] - a[i + 1]) * (b[i] - b[i + 1]) > 0)
            ans--;
    }
    vector<array<int, 2>> op;
    for (int i = 1; i < n; i++)
    {
        op.push_back({i, i + 1});
    }
    op.push_back({1, n});
    for (int i = 2; i < n; i++)
    {
        op.push_back({1, i});
        op.push_back({i, n});
    }
    ranges::sort(op);
    op.erase(unique(op.begin(), op.end()), op.end());
    for (auto [i, j] : op)
    {
        vector<int> pos = {i - 1, i, j - 1, j};
        ranges::sort(pos);
        pos.erase(unique(pos.begin(), pos.end()), pos.end());
        int val = calc(pos);
        swap(a[i], a[j]);
        int nval = calc(pos);
        swap(a[i], a[j]);
        if (nval > val)
            ans++;
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