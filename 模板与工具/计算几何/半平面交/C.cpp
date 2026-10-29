#include <bits/stdc++.h>
using namespace std;

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
// 多边形
// ==========================================
struct Polygon
{
    vector<Point> p; // 顶点按边界顺序存储，顺/逆时针均可
    Polygon() {}
    Polygon(const vector<Point> &p) : p(p) {}

    int size() const
    {
        return p.size();
    }

    // 有向面积的两倍：逆时针为正，顺时针为负
    double area2() const
    {
        double res = 0;
        for (int i = 0; i < size(); i++)
            res += cross(p[i], p[(i + 1) % size()]);
        return res;
    }

    // 多边形面积
    double area() const
    {
        return fabs(area2()) / 2;
    }

    // 多边形周长
    double perimeter() const
    {
        double res = 0;
        for (int i = 0; i < size(); i++)
            res += (p[i] - p[(i + 1) % size()]).len();
        return res;
    }

    // 判断是否为凸多边形，退化情形返回 false
    bool is_convex() const
    {
        if (size() < 3 || sign(area2()) == 0)
            return false;
        int pre = 0;
        for (int i = 0; i < size(); i++)
        {
            int cur = sign(cross(p[(i + 1) % size()] - p[i], p[(i + 2) % size()] - p[(i + 1) % size()]));
            if (cur == 0)
                continue;
            if (pre != 0 && cur != pre)
                return false;
            pre = cur;
        }
        return pre != 0;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<Point> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        double x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }
    vector adj(n + 1, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        ranges::sort(adj[i], greater<int>());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }
    if (adj[1][0] != n)
    {
        cout << (p[1] - p[n]).len() << '\n';
        return;
    }
    vector<int> link(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int cur = n;
        for (int j = 0; j < adj[i].size(); j++)
        {
            if (adj[i].size() && adj[i][j] == cur)
            {
                cur--;
            }
            else
                break;
        }
        link[i] = cur;
    }
    vector<Line> line;
    line.reserve(n);
    for (int i = 1; i < n; i++)
    {
        if (link[i] > i)
            line.emplace_back(p[link[i]], p[i] - p[link[i]]);
    }
    line.emplace_back(p[1], p[n] - p[1]);
    auto Unique = [&](vector<Line> &l)
    {
        vector<Line> ll;
        for (auto line : l)
        {
            if (ll.empty() || sign(cross(ll.back().v, line.v)) != 0)
                ll.push_back(line);
            else
            {
                if (ll.back().to_left(line.p) == 1)
                {
                    ll.back() = line;
                }
            }
        }
        return ll;
    };
    ranges::sort(line, [](Line &a, Line &b)
                 { return Polarcmp()(a.v, b.v); });
    line = Unique(line);
    deque<Line> dq;
    for (auto &l : line)
    {
        while (dq.size() > 1)
        {
            Point p = inter_l2l(dq[dq.size() - 2], dq.back());
            if (l.to_left(p) != -1)
                break;
            dq.pop_back();
        }
        while (dq.size() > 1)
        {
            Point p = inter_l2l(dq[0], dq[1]);
            if (l.to_left(p) != -1)
                break;
            dq.pop_front();
        }
        dq.push_back(l);
    }
    while (dq.size() > 2)
    {
        Point p = inter_l2l(dq[0], dq[1]);
        if (dq.back().to_left(p) != -1)
            break;
        dq.pop_front();
    }
    while (dq.size() > 2)
    {
        Point p = inter_l2l(dq[dq.size() - 2], dq.back());
        if (dq[0].to_left(p) != -1)
            break;
        dq.pop_back();
    }
    vector<Point> P;
    int s = dq.size();
    for (int i = 0; i < s; i++)
    {
        P.push_back(inter_l2l(dq[i], dq[(i + 1) % s]));
    }
    cout << fixed << setprecision(9) << Polygon(P).perimeter() - (p[1] - p.back()).len() << '\n';
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