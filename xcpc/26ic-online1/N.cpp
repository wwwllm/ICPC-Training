#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
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
    vector<int> Y;
    vector<Info> info;
    SegTree() : n(0) {}
    SegTree(int _n, vector<int> y) : Y(move(y)), n(_n), info(4 * _n) {};
    int findy(int y)
    {
        return ranges::lower_bound(Y, y) - Y.begin();
    }
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
struct SegTree2D
{
    int n;
    vector<SegTree> info;
    SegTree2D(const vector<vector<int>> &pY)
        : n(pY.size()), info(4 * n)
    {
        build(1, 0, n, pY);
    }
    // 区间查询[x,y)
    Info query(int p, int l, int r, int xl, int xr, int yl, int yr)
    {
        if (l >= xr || r <= xl)
            return {};
        if (l >= xl && r <= xr)
        {
            int L = info[p].findy(yl);
            int R = ranges::upper_bound(info[p].Y, yr) - info[p].Y.begin();
            return info[p].query(L, R);
        }
        int mid = l + r >> 1;
        return query(p << 1, l, mid, xl, xr, yl, yr) + query(p << 1 | 1, mid, r, xl, xr, yl, yr);
    };
    Info query(int xl, int xr, int yl, int yr)
    {
        return query(1, 0, n, xl, xr, yl, yr);
    };
    // 单点修改
    void modify(int p, int l, int r, int x, int y, int v)
    {
        info[p].modify(info[p].findy(y), v);
        if (r - l == 1)
        {
            return;
        }
        int mid = l + r >> 1;
        if (x < mid)
        {
            modify(p << 1, l, mid, x, y, v);
        }
        else
        {
            modify(p << 1 | 1, mid, r, x, y, v);
        }
    }
    void modify(int x, int y, int v)
    {
        modify(1, 0, n, x, y, v);
    }
    void build(int p, int l, int r,
               const vector<vector<int>> &pY)
    {
        if (r - l == 1)
        {
            info[p] = SegTree(pY[l].size(), pY[l]);
            return;
        }

        int mid = (l + r) >> 1;
        build(p << 1, l, mid, pY);
        build(p << 1 | 1, mid, r, pY);

        vector<int> resY;
        merge(info[p << 1].Y.begin(), info[p << 1].Y.end(),
              info[p << 1 | 1].Y.begin(), info[p << 1 | 1].Y.end(),
              back_inserter(resY));

        resY.erase(unique(resY.begin(), resY.end()), resY.end());

        int sz = resY.size();
        info[p] = SegTree(sz, move(resY));
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<array<int, 3>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    vector<int> dp(n + 1);
    vector<array<int, 2>> p(n + 1, {0, 0});
    vector<int> X, Y;
    X.push_back(0);
    int curx = 0, cury = 0;
    for (int i = 0; i <= n; i++)
    {
        curx += a[i][0] - a[i][1];
        cury += a[i][0] - a[i][2];
        p[i] = {curx, cury};
        X.push_back(curx);
    }

    auto findx = [&](int x) -> int
    {
        return ranges::lower_bound(X, x) - X.begin();
    };
    ranges::sort(X);
    X.erase(unique(X.begin(), X.end()), X.end());
    int m = X.size();
    vector<int> posX(n + 1);
    vector pY(m, vector<int>());
    for (int i = 0; i <= n; i++)
    {
        int idx = findx(p[i][0]);
        pY[idx].push_back(p[i][1]);
        posX[i] = idx;
    }
    auto findy = [&](int idxx, int y) -> int
    {
        return ranges::lower_bound(pY[idxx], y) - pY[idxx].begin();
    };
    for (int i = 0; i < m; i++)
    {
        ranges::sort(pY[i]);
        pY[i].erase(unique(pY[i].begin(), pY[i].end()), pY[i].end());
    }
    vector<int> prer(n + 1);
    for (int i = 1; i <= n; i++)
        prer[i] = prer[i - 1] + a[i][0];

    SegTree2D t(pY);
    auto insert = [&](int pos) -> void
    {
        int y = p[pos][1];
        int idxX = posX[pos];
        t.modify(idxX, y, dp[pos] - pos);
    };
    for (int i = 1; i <= n; i++)
    {
        insert(i - 1);
        dp[i] = max(dp[i - 1], t.query(0, posX[i] + 1, -inf, p[i][1]).max + i);
    }
    cout << dp[n] << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}