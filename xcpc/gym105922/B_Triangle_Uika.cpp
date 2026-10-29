#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

// https://codeforces.com/gym/105922
const double eps = 1e-9;
const double PI = acosl(-1.0);

double Acos(double x)
{
    if (x < -1)
        return PI;
    if (x > 1)
        return 0;
    return acosl(x);
};

int sign(double x)
{
    if (fabs(x) < eps)
        return 0;
    return x < 0 ? -1 : 1;
}

int cmp(double x, double y)
{
    if (fabs(x - y) < eps)
        return 0;
    return x < y ? -1 : 1;
}

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

    bool operator<(const Point &b) const
    {
        int c = cmp(x, b.x);
        if (c != 0)
            return c == -1;
        return cmp(y, b.y) == -1;
    }
};
typedef Point Vector;

// ========================================================================

double dot(Vector a, Vector b)
{
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b)
{
    return a.x * b.y - b.x * a.y;
}

double len(Vector a)
{
    return sqrt(dot(a, a));
}

// 法向量
Vector normal(Vector a)
{
    return Vector(-a.y, a.x);
}
void solve()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<Point> p1(n1), p2(n2), p3(n3);
    for (int i = 0; i < n1; i++)
    {
        double x, y;
        cin >> x >> y;
        p1[i] = {x, y};
    }
    for (int i = 0; i < n2; i++)
    {
        double x, y;
        cin >> x >> y;
        p2[i] = {x, y};
    }
    for (int i = 0; i < n3; i++)
    {
        double x, y;
        cin >> x >> y;
        p3[i] = {x, y};
    }
    vector<double> t, t1, t2, t3;
    t.emplace_back(0);
    t1 = t2 = t3 = t;
    double sum = 0;
    for (int i = 0; i + 1 < n1; i++)
    {
        Vector v = p1[i + 1] - p1[i];
        sum += len(v);
        t.emplace_back(sum);
        t1.emplace_back(sum);
    }
    sum = 0;
    for (int i = 0; i + 1 < n2; i++)
    {
        Vector v = p2[i + 1] - p2[i];
        sum += len(v);
        t.emplace_back(sum);
        t2.emplace_back(sum);
    }
    sum = 0;
    for (int i = 0; i + 1 < n3; i++)
    {
        Vector v = p3[i + 1] - p3[i];
        sum += len(v);
        t.emplace_back(sum);
        t3.emplace_back(sum);
    }
    if (t.size() == 1)
    {
        cout << fixed << setprecision(10) << abs(cross(p1[0] - p2[0], p1[0] - p3[0]) / 2) << '\n';
        return;
    }
    ranges::sort(t);
    t.erase(unique(t.begin(), t.end()), t.end());
    auto get_V = [&](const vector<Point> &p, const vector<double> &t, double now) -> pair<Point, Vector>
    {
        if (cmp(now, t.back()) != -1)
            return {p.back(), Vector(0, 0)};
        int pos = ranges::upper_bound(t, now + eps) - t.begin() - 1;
        pos = max(0LL, min((int)p.size() - 2, pos));

        Vector v = p[pos + 1] - p[pos];
        v = sign(len(v)) == 0 ? Vector(0, 0) : v / len(v);
        Point a = p[pos] + v * (now - t[pos]);
        return {a, v};
    };
    double ans = 0;
    for (int i = 0; i < t.size() - 1; i++)
    {
        double tl = t[i], tr = t[i + 1];
        if (cmp(tl, tr) == 0)
            continue;
        auto [a1, v1] = get_V(p1, t1, tl);
        auto [a2, v2] = get_V(p2, t2, tl);
        auto [a3, v3] = get_V(p3, t3, tl);

        Point b1 = a2 - a1, b2 = a3 - a1;
        Vector V1 = v2 - v1, V2 = v3 - v1;

        double A = cross(V1, V2), B = cross(V1, b2) + cross(b1, V2), C = cross(b1, b2);

        auto S = [&](double x)
        { return abs(A * x * x + B * x + C) / 2.0; };

        ans = max({ans, S(0), S(tr - tl)});

        if (sign(A) != 0)
        {
            double x = -B / (A * 2);
            if (cmp(x, 0) != -1 && cmp(x, tr - tl) != 1)
            {
                ans = max(ans, S(x));
            }
        }
    }
    cout << fixed << setprecision(10) << ans << '\n';
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