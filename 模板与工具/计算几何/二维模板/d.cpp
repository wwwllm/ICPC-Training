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

    // 点的大小比较：以 x 为第一关键字，y 为第二关键字（常用于排序）
    bool operator<(const Point &b) const
    {
        int c = cmp(x, b.x);
        if (c != 0)
            return c == -1;
        return cmp(y, b.y) == -1;
    }

    // 计算向量模长（两点间距离）
    double len() const
    {
        return hypot(x, y);
    }

    // 计算向量模长的平方
    double len2() const
    {
        return x * x + y * y;
    }

    // 求当前向量的法向量（逆时针旋转 90 度）
    Vector normal() const
    {
        return Point(-y, x);
    }

    // 求该点/向量关于原点的极角，范围在 [-pi, pi] 之间
    double p_angle() const
    {
        return atan2(y, x);
    }

    // 向量单位化（归一化）
    Vector unit() const
    {
        double l = this->len();
        if (sign(l) == 0)
            return (*this);
        return (*this) / l;
    }

    // 向量逆时针旋转给定弧度 angle
    Vector rotate(double angle) const
    {
        double c = cos(angle), s = sin(angle);
        return Point(x * c - y * s, x * s + y * c);
    }
};

// 计算两个向量的点积（内积）
double dot(const Vector &a, const Vector &b)
{
    return a.x * b.x + a.y * b.y;
}

// 计算两个向量的叉积（外积）
double cross(const Vector &a, const Vector &b)
{
    return a.x * b.y - b.x * a.y;
}

// 计算两个向量的夹角，范围在 [0, pi] 之间
double get_angle(const Vector &a, const Vector &b)
{
    return fabs(atan2(cross(a, b), dot(a, b)));
}

// 计算以点 a 为起点，ab 和 ac 构成的平行四边形的有向面积
double area(const Point &a, const Point &b, const Point &c)
{
    return cross(b - a, c - a);
}

// 判断三点是否共线
bool is_collinear(const Point &a, const Point &b, const Point &c)
{
    return sign(cross(b - a, c - a)) == 0;
}

// 求当前点关于点 o 的对称点
Point reflect(const Point &p, const Point &o)
{
    return o * 2.0 - p;
}

// 精准全平面极角排序比较器（按逆时针排序，不使用 atan2，防精度误差）
struct Polarcmp
{
    // 象限判断：1->右上(含X正), 2->左上(含Y正), 3->左下(含X负), 4->右下(含Y负)
    int quad(const Point &p) const
    {
        if (p.x >= 0 && p.y >= 0)
            return 1;
        if (p.x < 0 && p.y >= 0)
            return 2;
        if (p.x < 0 && p.y < 0)
            return 3;
        return 4;
    }

    // 比较函数
    bool operator()(const Point &a, const Point &b) const
    {
        int qa = quad(a), qb = quad(b);
        if (qa != qb)
            return qa < qb; // 象限不同，象限小的排前面
        double c = cross(a, b);
        if (sign(c) != 0)
            return sign(c) > 0;     // 象限相同，叉积大于0说明 b 在 a 的左侧（逆时针）
        return a.len2() < b.len2(); // 极角相同时，距离近的排前面
    }
};

// ==========================================
// 直线
// ==========================================
struct Line
{
    Point p;  // 直线上的基准点
    Vector v; // 直线的方向向量（参数方程：p + t*v）
    Line() {}
    Line(Point p, Vector v) : p(p), v(v) {}

    // 判定两条直线的关系
    // 返回值：0 相交 | 1 平行 | 2 重合
    static int line_relation(const Line &a, const Line &b)
    {
        if (sign(cross(a.v, b.v)) != 0)
            return 0;
        if (sign(cross(a.v, b.p - a.p)) == 0)
            return 2;
        return 1;
    }

    // 判定点 a 与有向直线（p -> p+v） Orient/To-Left 的位置关系
    // 返回值：1 在直线左侧 | -1 在直线右侧 | 0 在直线上
    int to_left(const Point &a) const
    {
        return sign(cross(v, a - p));
    }

    // 计算点 a 到该直线的垂直距离
    double dist(const Point &a) const
    {
        return fabs(cross(v, a - p)) / v.len();
    }

    // 求点 a 在该直线上的垂直投影点
    Point proj(const Point &a) const
    {
        return p + v * (dot(a - p, v) / v.len2());
    }

    // 求点 a 关于该直线的对称点（镜像点）
    Point reflect(const Point &a) const
    {
        Point pr = proj(a);
        return pr * 2.0 - a;
    }
};

// 求两条直线 a 和 b 的唯一交点（需提前断定它们不平行）
Point inter_l2l(const Line &a, const Line &b)
{
    assert(sign(cross(a.v, b.v)) != 0);
    Vector u = a.p - b.p;
    double t = cross(b.v, u) / cross(a.v, b.v);
    return a.p + a.v * t;
}

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
        if (sign(cross(p - a, p - b)) == 0 && sign(dot(p - a, p - b)) <= 0)
            return 1;
        return 0;
    }

    // 判断两线段是否相交：-1 端点处接触相交 | 1 严格在内部交叉相交 | 0 互不相交
    int is_inter(const Segment &s) const
    {
        if (on_segment(s.a) != 0 || on_segment(s.b) != 0 || s.on_segment(a) != 0 || s.on_segment(b) != 0)
            return -1;
        double c1 = cross(b - a, s.a - a), c2 = cross(b - a, s.b - a);
        double c3 = cross(s.b - s.a, a - s.a), c4 = cross(s.b - s.a, b - s.a);
        return (sign(c1) * sign(c2) < 0 && sign(c3) * sign(c4) < 0) ? 1 : 0;
    }

    // 计算点 p 到当前线段的最短距离
    double dist(const Point &p) const
    {
        if (a == b)
            return (p - a).len();
        Vector v1 = b - a, v2 = p - a, v3 = p - b;
        if (sign(dot(v1, v2)) < 0)
            return v2.len();
        if (sign(dot(v1, v3)) > 0)
            return v3.len();
        Line l{a, b - a};
        return l.dist(p); // 正常向线段作垂线距离
    }

    // 计算当前线段到另一条线段 s 的最短距离
    double dist(const Segment &s) const
    {
        if (is_inter(s) != 0)
            return 0;
        return min({dist(s.a), dist(s.b), s.dist(a), s.dist(b)});
    }
};

// 求两条线段的交点坐标（调用前必须先确保 is_inter 返回非 0 状态）
Point get_seg_intersection(const Segment &s1, const Segment &s2)
{
    assert(s1.is_inter(s2) == 0);
    Line l1{s1.a, s1.b - s1.a};
    Line l2{s2.a, s2.b - s2.a};
    return inter_l2l(l1, l2);
}
void solve()
{
    int n;
    cin >> n;
    vector<Point> a(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    auto check = [&](Line &l) -> double
    {
        vector<pair<Point, int>> re;
        for (int i = 0; i < n; i++)
        {
            auto u = a[i], v = a[(i + 1) % n];
            int x = l.to_left(u), y = l.to_left(v);
            if (x != y)
            {
                re.push_back({inter_l2l(l, Line(u, v - u)), x - y});
            }
        }
        if (re.empty())
        {
            return 0.0;
        }
        ranges::sort(re, [&](pair<Point, int> &a, pair<Point, int> b)
                     { return a.first < b.first; });
        int m = re.size();
        int cur = 0;
        double res = 0, len = 0;
        auto p = re[0].first;
        for (int i = 0; i < m; i++)
        {
            auto u = re[i].first;
            if (cur != 0)
            {
                len += (u - p).len();
            }
            else
            {
                res = max(res, len);
                len = 0;
            }
            cur += re[i].second;
            p = u;
        }
        res = max(res, len);
        return res;
    };
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            Line l{a[i], a[j] - a[i]};
            ans = max(ans, check(l));
        }
    }
    cout << fixed << setprecision(9) << ans << '\n';
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