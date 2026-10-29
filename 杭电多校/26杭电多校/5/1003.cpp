#include <bits/stdc++.h>
#define int long long
using namespace std;

const double eps = 1e-9;
const double pi = acos(-1.0);
const int mod = 998244353;

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
int dot(const Vector &a, const Vector &b)
{
    return a.x * b.x + a.y * b.y;
}

// 计算两个向量的叉积（外积）
int cross(const Vector &a, const Vector &b)
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
        int c = cross(a, b);
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

// 求两条直线 a 和 b 的唯一交点（需提前断定它们不平行）
Point inter_l2l(const Line &a, const Line &b)
{
    assert(sign(cross(a.v, b.v)) != 0);
    Vector u = a.p - b.p;
    double t = cross(b.v, u) / cross(a.v, b.v);
    return a.p + a.v * t;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<Point, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        Point p;
        int val;
        cin >> p >> val;
        a[i] = {p, val};
    }
    ranges::sort(a, [](auto &a, auto &b)
                 { return a.first < b.first; });
    int ans = 0;
    auto check = [&](int i, int j) -> bool
    { return a[i].second ^ a[j].second; };
    vector<vector<double>> r(n);
    for (int p = 0; p < n; p++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i != p)
            {
                r[p].push_back((a[i].first - a[p].first).p_angle());
                r[p].push_back((a[p].first - a[i].first).p_angle());
            }
        }
        ranges::sort(r[p]);
        r[p].erase(unique(r[p].begin(), r[p].end()), r[p].end());
    }
    auto find = [&](int p, double ang) -> int
    {
        return ranges::lower_bound(r[p], ang) - r[p].begin();
    };
    vector<vector<int>> L(n, vector<int>(n)), R(n, vector<int>(n));
    for (int q = 0; q < n; q++)
    {
        for (int x = 0; x < n; x++)
        {
            L[q][x] = find(q, (a[x].first - a[q].first).p_angle());
            R[q][x] = find(q, (a[q].first - a[x].first).p_angle());
        }
    }
    for (int s = 0; s < n; s++)
    {
        vector dp(n, vector<int>(n));
        for (int i = s; i < n; i++)
        {
            if (check(s, i))
            {
                dp[s][i] = 1;
            }
        }
        int m;
        vector<int> pre;
        auto build = [&](int q)
        {
            pre.assign(r[q].size(), 0);
            for (int i = 0; i < n; i++)
            {
                if (i != q)
                {
                    int pos = L[q][i];
                    (pre[pos] += dp[i][q]) %= mod;
                }
            }
            m = pre.size();
            for (int i = 1; i < m; i++)
            {
                (pre[i] += pre[i - 1]) %= mod;
            }
        };
        auto Sum = [&](int l, int r) -> int
        {
            if (l > r)
                return 0;

            return (pre[r] - (l == 0 ? 0 : pre[l - 1]) + mod) % mod;
        };

        auto query = [&](int q, int x) -> int
        {
            int l = L[q][x];
            int r = R[q][x];

            if (l < r)
            {
                return Sum(l + 1, r - 1);
            }
            else
            {
                int res = Sum(l + 1, m - 1);
                (res += Sum(0, r - 1)) %= mod;
                return res;
            }
        };
        for (int q = s + 1; q < n; q++)
        {
            build(q);
            for (int x = q; x < n; x++)
            {
                if (!check(x, q))
                    continue;
                (dp[q][x] += query(q, x)) %= mod;
            }
        }
        for (int q = n - 1; q > s; q--)
        {
            build(q);
            for (int x = q - 1; x >= s; x--)
            {
                if (!check(q, x))
                    continue;
                (dp[q][x] += query(q, x)) %= mod;
            }
        }
        for (int i = s; i < n; i++)
        {
            if (check(i, s))
            {
                (ans += dp[i][s]) %= mod;
            }
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}