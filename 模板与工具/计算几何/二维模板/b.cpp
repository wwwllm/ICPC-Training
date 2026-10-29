#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://ac.nowcoder.com/acm/contest/27249/B

const double eps = 1e-9;
const double pi = acosl(-1.0);

double Acos(double x)
{
    if (x < -1)
        return pi;
    if (x > 1)
        return 0;
    return acosl(x);
}
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

    bool operator<(const Point &b) const // x为第一关键字
    {
        int c = cmp(x, b.x);
        if (c != 0)
            return c == -1;
        return cmp(y, b.y) == -1;
    }

    double len()
    {
        return hypot(x, y);
    }
};
typedef Point Vector;
double cross(Vector a, Vector b)
{
    return a.x * b.y - b.x * a.y;
}
double dot(Vector a, Vector b)
{
    return a.x * b.x + a.y * b.y;
}
double get_angle(Vector a, Vector b)
{
    return fabs(atan2l(cross(a, b), dot(a, b)));
}
bool on_edge(Point p, Point a, Point b)
{
    return sign(cross(p - a, p - b)) == 0 && sign(dot(p - a, p - b)) != 1;
}
void solve()
{
    int n;
    cin >> n;
    vector<Point> a(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    int m;
    cin >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        Point o = {x, y};
        int res = 0;
        bool ok = 1;
        for (int i = 0; i < n; i++)
        {
            auto u = a[i], v = a[(i + 1) % n];
            if (on_edge(o, u, v))
            {
                ok = 0;
                break;
            }
            if (u.y <= o.y)
            {
                if (v.y > o.y && sign(cross(o - u, v - u)) == -1)
                    res++;
            }
            if (u.y >= o.y)
            {
                if (v.y < o.y && sign(cross(o - u, v - u)) == 1)
                    res--;
            }
        }
        if (!ok)
            cout << "EDGE\n";
        else
            cout << res << '\n';
    }
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