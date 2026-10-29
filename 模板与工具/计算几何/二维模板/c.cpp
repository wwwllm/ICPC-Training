#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://ac.nowcoder.com/acm/contest/27249/C

const double eps = 1e-9;
const double pi = acosl(-1.0);

double Acos(double x)
{
    if (x < -1)
        return pi;
    if (x > 1)
        return 0;
    return acosl(x);
}
int sign(double x)
{
    if (fabs(x) < eps)
        return 0;
    return x < 0 ? -1 : 1;
}
int cmp(double x, double y)
{
    return sign(x - y);
}
struct Point
{
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
    Point operator*(double k) const { return Point(x * k, y * k); }
    Point operator/(double k) const { return Point(x / k, y / k); }

    bool operator==(const Point &b) const
    {
        return cmp(x, b.x) == 0 && cmp(y, b.y) == 0;
    }

    bool operator<(const Point &b) const // x为第一关键字
    {
        int c = cmp(x, b.x);
        if (c != 0)
            return c == -1;
        return cmp(y, b.y) == -1;
    }

    double len()
    {
        return hypot(x, y);
    }
};
typedef Point Vector;
double cross(Vector a, Vector b)
{
    return a.x * b.y - b.x * a.y;
}
double dot(Vector a, Vector b)
{
    return a.x * b.x + a.y * b.y;
}
struct Line
{
    Point p;  // 直线上的点
    Vector v; // 方向向量（参数方程：p + t*v）
    Line(Point p, Vector v) : p(p), v(v) {}
};

// 两直线交点
double get_line_intersection(Line a, Line b)
{
    assert(sign(cross(a.v, b.v)) != 0); // 保证两直线不重合
    Vector u = a.p - b.p;
    double t = cross(b.v, u) / cross(a.v, b.v);
    return t;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    Point s, t;
    int x, y;
    cin >> x >> y;
    s = {x, y};
    cin >> x >> y;
    t = {x, y};
    vector<Point> a(n);
    vector d(n, vector<double>());
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        a[i] = {x, y};
    }
    Line l(s, t - s);
    auto len = (t - s).len();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            Line u(a[i], a[j] - a[i]);
            auto tmp = get_line_intersection(l, u);
            if (sign(tmp) >= 0 && sign(tmp - 1) <= 0)
                d[i].push_back(tmp);
        }
        ranges::sort(d[i]);
    }
    while (m--)
    {
        int h, k;
        cin >> h >> k;
        h--;
        if (d[h].size() < k)
            cout << -1 << '\n';
        else
        {
            auto p = (l.p + l.v * d[h][k - 1]);
            cout << p.x << ' ' << p.y << '\n';
        }
    }
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