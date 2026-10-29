#include <bits/stdc++.h>
#define int long long
using namespace std;

int sign(int x)
{
    if (abs(x) == 0)
        return 0;
    return x < 0 ? -1 : 1;
}

int cmp(int x, int y)
{
    return sign(x - y);
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

    // 计算向量模长的平方
    int len2() const
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
    int diameter()
    {
        int n = p.size();
        if (n <= 1)
            return 0;
        if (n == 2)
            return (p[0] - p[1]).len2();
        int ans = 0;
        for (int i = 0, j = i + 1; i < n; i++)
        {
            auto u = p[i], v = p[(i + 1) % n];
            while (abs(cross(v - u, p[j] - u)) < abs(cross(v - u, p[(j + 1) % n] - u)))
            {
                j = (j + 1) % n;
            }
            ans = max({ans, (u - p[j]).len2(), (v - p[j]).len2()});
        }
        return ans;
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
    cout << c.diameter() << '\n';
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