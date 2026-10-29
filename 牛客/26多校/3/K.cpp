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
};

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
        return sign(cross(v, a - p));
    }
};
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

void solve()
{
    int n;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }
    Line cur(p[0], p[1] - p[0]);
    for (int i = 1; i < n - 1; i++)
    {
        auto u = p[i + 1];
        if (cur.to_left(u) == 1)
        {
            cout << "LEFT ";
        }
        else if (cur.to_left(u) == -1)
        {
            cout << "RIGHT ";
        }
        else
        {
            cout << "STRAIGHT ";
        }
        cur = Line(p[i], p[i + 1] - p[i]);
    }
    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}