#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

using T = double;
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
T dot(const Vector &a, const Vector &b)
{
    return a.x * b.x + a.y * b.y;
}

// 计算两个向量的叉积（外积）
T cross(const Vector &a, const Vector &b)
{
    return a.x * b.y - b.x * a.y;
}

void solve()
{
    int n;
    cin >> n;
    vector<Point> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        b.push_back(a[i].x);
    }
    ranges::sort(b);
    b.erase(unique(b.begin(), b.end()), b.end());
    int m = b.size();
    vector<int> cnt(m);
    for (int i = 0; i < n; i++)
    {
        int idx = ranges::lower_bound(b, a[i].x) - b.begin();
        cnt[idx]++;
    }
    auto query = [&](int p, int q)
    {
        cout << "? " << p << ' ' << q << endl;
        double r, c;
        cin >> r >> c;
        return r / c;
    };
    auto answer = [&](int p, int q)
    {
        cout << "! " << p << ' ' << q << endl;
    };
    vector<double> len(m, -1);
    if (cnt[0] == 1)
        len[0] = 0;
    if (cnt[m - 1] == 1)
        len[m - 1] = 0;
    double res = 0;
    for (int i = 0; i < m - 1; i++)
    {
        int j = i + 1;
        if (cnt[i] > 1 || cnt[j] > 1)
        {
            double l = query(b[i] + b[j], 2);
            int d = b[j] - b[i];
            auto s = d * l;
            res = res + s;
        }
        else
        {
            if (len[i] == -1)
            {
                len[i] = query(b[i], 1);
            }
            if (len[j] == -1)
            {
                len[j] = query(b[j], 1);
            }
            double l = len[i] + len[j];
            double d = b[j] - b[i];
            auto s = l * d / 2;
            res = res + s;
        }
    }
    int ans = llround(res * 2);
    int g = gcd(ans, 2);
    answer(ans / g, 2 / g);
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