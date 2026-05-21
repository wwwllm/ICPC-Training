#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
struct Mat
{
    int n;
    vector<vector<int>> M;
    Mat(int r) : n(r), M(r, vector<int>(r, inf)) {};
    Mat unit()
    {
        Mat res(n);
        for (int i = 0; i < n; i++)
            res.M[i][i] = 0;
        return res;
    }
    Mat operator*(const Mat &b) const
    {
        Mat res(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    res.M[i][j] = min(res.M[i][j], M[i][k] + b.M[k][j]);
                }
            }
        }
        return res;
    }
};
struct Info
{
    Mat M;
    Info() : M(Mat(2).unit()) {};
    Info(int val) : M(2)
    {
        M.M[0][0] = inf, M.M[0][1] = 0;
        M.M[1][0] = val, M.M[1][1] = val;
    };
    Info operator+(const Info &other) const
    {
        Info res;
        res.M = other.M * M;
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    SegTree t(n + 1);
    for (int i = 1; i <= n; i++)
    {
        t.modify(i, a[i]);
    }
    int ans = inf;
    for (int l = 1; l <= n; l++)
    {
        int r = l + k - 1;
        if (r <= n)
        {
            auto M = t.query(l + 1, r + 1).M;
            ans = min(ans, a[l] + M.M[1][1]);
        }
        r++;
        if (r <= n)
        {
            auto M = t.query(l + 1, r + 1).M;
            ans = min(ans, a[l] + M.M[1][1]);
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