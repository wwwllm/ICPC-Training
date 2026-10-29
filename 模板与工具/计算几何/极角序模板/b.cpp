#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://ac.nowcoder.com/acm/contest/27675/B
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

    // 计算向量模长的平方
    int len2() const
    {
        return x * x + y * y;
    }
};

// 计算两个向量的叉积（外积）
int cross(const Vector &a, const Vector &b)
{
    return a.x * b.y - b.x * a.y;
}

// 求当前点关于点 o 的对称点
Point reflect(const Point &p, const Point &o)
{
    return o * 2.0 - p;
}

// 精准全平面极角排序比较器（按逆时针排序，不使用 atan2，防精度误差）
struct Polarcmp
{
    Point o;
    Polarcmp(Point o = {0, 0}) : o(o) {};
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
    bool operator()(const Point &A, const Point &B) const
    {
        auto a = A - o, b = B - o;
        if (a.y < 0)
        {
            a = reflect(A, o) - o;
        }
        if (b.y < 0)
        {
            b = reflect(B, o) - o;
        }
        int qa = quad(a), qb = quad(b);
        if (qa != qb)
            return qa < qb; // 象限不同，象限小的排前面
        int c = cross(a, b);
        if (sign(c) != 0)
            return sign(c) > 0;     // 象限相同，叉积大于0说明 b 在 a 的左侧（逆时针）
        return a.len2() < b.len2(); // 极角相同时，距离近的排前面
    }
};
struct Segment
{
    Point a, b; // 线段的两个端点
    Segment() {}
    Segment(Point a, Point b) : a(a), b(b) {}
};
void solve()
{
    int n;
    cin >> n;
    vector<Segment> a(n);
    vector<Point> o;
    for (int i = 0; i < n; i++)
    {
        int x0, x1, y;
        cin >> x0 >> x1 >> y;
        a[i] = {{x0, y}, {x1, y}};
        o.push_back({x0, y});
        o.push_back({x1, y});
    }
    auto calc = [&](Point o)
    {
        int ans = 0;
        vector<pair<Point, int>> p;
        for (int i = 0; i < n; i++)
        {
            auto [x, y] = a[i];
            if (x == o || y == o)
                ans += abs(x.x - y.x);
            else if (x.y != o.y)
            {
                p.push_back({x, i * 2});
                p.push_back({y, i * 2 + 1});
            }
        }
        if (p.empty())
            return ans;
        int m = p.size();
        ranges::sort(p, [&](const auto &A, const auto &B)
                     { return Polarcmp(o)(A.first, B.first); });
        auto check = [&](Point A, Point B)
        {
            auto a = A - o, b = B - o;
            if (a.y < 0)
                a = reflect(A, o) - o;
            if (b.y < 0)
                b = reflect(B, o) - o;
            return cross(a, b) == 0;
        };
        vector<int> res(m + 1);
        vector<int> posx(n), posy(n);
        int idx = 0;
        for (int i = 0; i < m; i++)
        {
            if (i > 0 && !check(p[i - 1].first, p[i].first))
            {
                idx++;
            }
            int seg = p[i].second / 2;
            int type = p[i].second % 2;
            if (type == 0)
                posx[seg] = idx;
            else
                posy[seg] = idx;
        }
        for (int i = 0; i < n; i++)
        {
            auto [x, y] = a[i];
            if (x.y == o.y)
                continue;
            int pu = posx[i], pv = posy[i];
            if (pu > pv)
                swap(pu, pv);
            int len = abs(x.x - y.x);
            res[pu] += len;
            res[pv + 1] -= len;
        }
        for (int i = 1; i <= m; i++)
        {
            res[i] += res[i - 1];
        }
        return *ranges::max_element(res) + ans;
    };
    int ans = 0;
    for (auto p : o)
    {
        ans = max(ans, calc(p));
    }
    cout << ans << '\n';
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