#include <bits/stdc++.h>
#define int long long
using namespace std;

const double eps = 1e-9;
const double pi = acos(-1.0);

using T = int;
int sign(T x)
{
    // x为int改成x==0
    if (x == 0)
        return 0;
    return x < 0 ? -1 : 1;
}

int cmp(T x, T y)
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
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}

    Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
    Point operator*(T k) const { return Point(x * k, y * k); }
    Point operator/(T k) const { return Point(x / k, y / k); }

    friend istream &operator>>(istream &in, Point &p)
    {
        in >> p.x >> p.y;
        return in;
    }

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
    T len2() const
    {
        return x * x + y * y;
    }
};

// 计算两个向量的点积（内积）
T dot(const Vector &a, const Vector &b)
{
    return a.x * b.x + a.y * b.y;
}

// 计算两个向量的叉积（外积）
T cross(const Vector &a, const Vector &b)
{
    return a.x * b.y - b.x * a.y;
}

// 计算以点 a 为起点，ab 和 ac 构成的平行四边形的有向面积
T area(const Point &a, const Point &b, const Point &c)
{
    return cross(b - a, c - a);
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
    T area2() const
    {
        T res = 0;
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
    T perimeter2() const
    {
        T res = 0;
        for (int i = 0; i < size(); i++)
            res += (p[i] - p[(i + 1) % size()]).len2();
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

void solve(int pid)
{
    int n;
    cin >> n;
    vector<Point> p(n);
    if (pid != 0)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        Convex C(p);
        int m = C.p.size();
        cout << m << '\n';
        for (int i = 0; i < m; i++)
        {
            cout << C.p[i].x << ' ' << C.p[i].y << '\n';
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        for (int i = 0; i < 3; i++)
        {
            int siz;
            cin >> siz;
            for (int j = 0; j < siz; j++)
            {
                Point x;
                cin >> x;
                p.push_back(x);
            }
        }
        n = p.size();
        Convex C(p);
        int m = C.p.size();
        cout << m << '\n'
             << abs(C.area2()) << '\n'
             << C.perimeter2() << '\n';
    }
}
signed main(int argc, char *argv[])
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int pid = atoi(argv[1]);
    solve(pid);
    return 0;
}