#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

const int inf = 1e18;
const double pi = acosl(-1.0);
const double eps = 1e-15;
struct Point
{
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
    Point operator*(double k) const { return Point(x * k, y * k); }
    Point operator/(double k) const { return Point(x / k, y / k); }
};
int sign(double x)
{
    if (fabs(x) < eps)
        return 0;
    return x < 0 ? -1 : 1;
}
double cross(Point a, Point b)
{
    return a.x * b.y - b.x * a.y;
}
double p_angle(Point a)
{
    return atan2l(a.y, a.x);
}
double dot(Point a, Point b)
{
    return a.x * b.x + a.y * b.y;
}
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
    cout << fixed << setprecision(12);
    vector<Point> p(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }
    ranges::sort(p, [&](Point a, Point b)
                 { 
        int ha = (a.y > 0 or a.y == 0 and a.x > 0);
        int hb = (b.y > 0 or b.y == 0 and b.x > 0);
        if (ha != hb)
           return ha < hb;
        int c = cross(a, b);
        return c > 0; });
    vector<int> l(n);
    vector<double> r(n);
    for (int i = 0; i < n; i++)
    {
        l[i] = dot(p[i], p[i]);
        r[i] = p_angle(p[i]);
    }
    for (int i = 1; i < n; i++)
    {
        if (sign(r[i] - r[i - 1]) == 0)
        {
            l[i] = max(l[i], l[i - 1]);
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (sign(r[i] - r[i + 1]) == 0)
        {
            l[i] = max(l[i], l[i + 1]);
        }
    }
    SegTree t(n);
    for (int i = 0; i < n; i++)
        t.modify(i, l[i]);
    double ans = 1e18;
    for (int i = 0; i < n; i++)
    {
        int j = (k + i - 1) % n;
        double a = r[j] - r[i];
        double len = 0.0;
        if (j < i)
        {
            len = max(t.query(0, j + 1).max, t.query(i, n).max);
            a += 2 * pi;
        }
        else
        {
            len = t.query(i, j + 1).max;
        }
        ans = min(ans, a * len * 0.5);
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
}