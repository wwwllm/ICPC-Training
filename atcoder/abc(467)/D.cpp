#include <bits/stdc++.h>
#define int long long
using namespace std;

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
        return x == b.x && y == b.y;
    }
    friend istream &operator>>(istream &in, Point &p)
    {
        in >> p.x >> p.y;
        return in;
    }
    // 求当前向量的法向量（逆时针旋转 90 度）
    Vector normal() const
    {
        return Point(-y, x);
    }
};
// 计算两个向量的叉积（外积）
double cross(const Vector &a, const Vector &b)
{
    return a.x * b.y - b.x * a.y;
}
struct Line
{
    Point p;  // 直线上的基准点
    Vector v; // 直线的方向向量（参数方程：p + t*v）
    Line() {}
    Line(Point p, Vector v) : p(p), v(v) {}
};
// 判定两条直线的关系
// 返回值：0 相交 | 1 平行 | 2 重合
static int line_relation(const Line &a, const Line &b)
{
    if (cross(a.v, b.v))
        return 0;
    if (cross(a.v, b.p - a.p) == 0)
        return 2;
    return 1;
}
void solve()
{
    Point p1, p2, q1, q2;
    cin >> p1 >> p2 >> q1 >> q2;
    Line l1((p1 + p2), (p2 - p1).normal()), l2((q1 + q2), (q2 - q1).normal());
    if (line_relation(l1, l2) != 1)
    {
        cout << "Yes\n";
    }
    else
        cout << "No\n";
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