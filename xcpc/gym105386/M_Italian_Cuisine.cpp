#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105386/problem/M
using i128 = __int128;
const double eps = 1e-9;
const double pi = acos(-1.0);

int sign(int x)
{
    if (x == 0)
        return 0;
    return x < 0 ? -1 : 1;
}

int cmp(int x, int y)
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

// 计算以点 a 为起点，ab 和 ac 构成的平行四边形的有向面积
int area(const Point &a, const Point &b, const Point &c)
{
    return cross(b - a, c - a);
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

void solve()
{
    int n;
    cin >> n;
    Point o;
    int r;
    int x, y;
    cin >> x >> y >> r;
    o = {x, y};
    vector<Point> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        a[i] = {x, y};
        a.push_back(a[i]);
    }
    int s = 0;
    int ans = 0;
    auto check = [&](Line l) -> bool
    {
        if (l.to_left(o) != 1)
            return 0;
        i128 c = cross(l.v, o - l.p);
        c *= c;
        return c >= (i128)r * r * l.v.len2();
    };
    for (int i = 0, j = 0; i < n; i++)
    {
        if (j < i)
            j = i, s = 0;
        while (j + 1 < 2 * n && check(Line(a[i], a[j + 1] - a[i])))
        {
            s += area(a[i], a[j], a[j + 1]);
            j++;
        }
        ans = max(ans, s);
        s -= area(a[i], a[i + 1], a[j]);
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}