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
};

// ==========================================
// 凸包
// ==========================================
struct Convex : Polygon
{
    Convex() {}
    Convex(vector<Point> q, bool keep_collinear = false)
    {
        build(q, keep_collinear);
    }

    // Andrew 单调链：默认删除边上的共线点；keep_collinear 为 true 时保留
    void build(vector<Point> q, bool keep_collinear = false)
    {
        sort(q.begin(), q.end());
        q.erase(unique(q.begin(), q.end()), q.end());
        p.clear();
        if (q.size() <= 1)
        {
            p = q;
            return;
        }
        bool collinear = true;
        for (int i = 2; i < (int)q.size(); i++)
            if (sign(cross(q[1] - q[0], q[i] - q[0])) != 0)
            {
                collinear = false;
                break;
            }
        if (collinear)
        {
            p = keep_collinear ? q : vector<Point>{q.front(), q.back()};
            return;
        }

        auto check = [&](const Point &a, const Point &b, const Point &c)
        {
            int s = sign(cross(b - a, c - b));
            return keep_collinear ? s < 0 : s <= 0;
        };

        for (const Point &a : q)
        {
            while (p.size() >= 2 && check(p[p.size() - 2], p.back(), a))
                p.pop_back();
            p.push_back(a);
        }
        int lower_size = p.size();
        for (int i = (int)q.size() - 2; i >= 0; i--)
        {
            while ((int)p.size() > lower_size && check(p[p.size() - 2], p.back(), q[i]))
                p.pop_back();
            p.push_back(q[i]);
        }
        p.pop_back(); // 不重复存储起点
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }
    Convex c(p);
    cout << fixed << setprecision(9) << c.perimeter() << '\n';
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