#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://ac.nowcoder.com/acm/contest/27249/D
const double eps = 1e-9;
const double pi = acos(-1.0);

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

double Acos(double x)
{
    if (x < -1)
        return pi;
    if (x > 1)
        return 0;
    return acos(x);
}

// ==========================================
// 点与向量的结构体
// ==========================================
struct Point;
using Vector = Point;

struct Point
{
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
    Point operator*(double k) const { return Point(x * k, y * k); }
    Point operator/(double k) const { return Point(x / k, y / k); }

    bool operator==(const Point &b) const
    {
        return cmp(x, b.x) == 0 && cmp(y, b.y) == 0;
    }

    // 点的大小比较：以 x 为第一关键字，y 为第二关键字（常用于排序）
    bool operator<(const Point &b) const
    {
        int c = cmp(x, b.x);
        if (c != 0)
            return c == -1;
        return cmp(y, b.y) == -1;
    }
};

// 计算两个向量的点积（内积）
int dot(const Vector &a, const Vector &b)
{
    return a.x * b.x + a.y * b.y;
}

// 计算两个向量的叉积（外积）
int cross(const Vector &a, const Vector &b)
{
    return a.x * b.y - b.x * a.y;
}

// ==========================================
// 直线
// ==========================================
struct Line
{
    Point p;  // 直线上的基准点
    Vector v; // 直线的方向向量（参数方程：p + t*v）
    Line() {}
    Line(Point p, Vector v) : p(p), v(v) {}

    // 判定点 a 与有向直线（p -> p+v） Orient/To-Left 的位置关系
    // 返回值：1 在直线左侧 | -1 在直线右侧 | 0 在直线上
    int to_left(const Point &a) const
    {
        int cp = cross(v, a - p);
        if (cp > 0)
            return 1;
        if (cp < 0)
            return -1;
        return 0;
    }
};

// ==========================================
// 线段
// ==========================================
struct Segment
{
    Point a, b; // 线段的两个端点
    Segment() {}
    Segment(Point a, Point b) : a(a), b(b) {}

    // 判断点 p 与当前线段的位置关系：-1 在端点上 | 1 严格在线段内部 | 0 不在线段上
    int on_segment(const Point &p) const
    {
        if (p == a || p == b)
            return -1;
        if (cross(p - a, p - b) == 0 && dot(p - a, p - b) <= 0)
            return 1;
        return 0;
    }
};

void solve()
{
    Point a, b, c;
    int x, y;
    cin >> x >> y;
    a = {x, y};
    cin >> x >> y;
    b = {x, y};
    cin >> x >> y;
    c = {x, y};
    Line l1(a, b - a), l2(b, c - b), l3(c, a - c);
    Segment s1(a, b), s2(b, c), s3(c, a);
    bool ok = l1.to_left(c) == 0;
    int n;
    cin >> n;
    while (n--)
    {
        cin >> x >> y;
        Point t = {x, y};
        if (s1.on_segment(t) || s2.on_segment(t) || s3.on_segment(t))
        {
            cout << "YES\n";
            continue;
        }
        if (ok)
        {
            cout << "NO\n";
            continue;
        }
        int c1 = l1.to_left(t), c2 = l2.to_left(t), c3 = l3.to_left(t);
        if (c1 == c2 && c3 == c2)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
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