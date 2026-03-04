#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const double EPS = 1e-9;
inline int sgn(double x)
{
    return x < -EPS ? -1 : (x > EPS ? 1 : 0);
}
struct point
{
    double x, y;
    point(const double &x, const double &y) : x(x), y(y) {};
    point operator+(const point &b) const
    {
        return point(x + b.x, y + b.y);
    }
    point operator-(const point &b) const
    {
        return point(x - b.x, y - b.y);
    }
    point operator*(const double &k) const
    {
        return point(x * k, y * k);
    }
    point operator/(const double &k) const
    {
        return point(x / k, y / k);
    }
    bool operator==(const point &b) const
    {
        return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
    }
    double norm()
    { // 求模长
        return sqrt(x * x + y * y);
    }
    point rotate(double rad) // 向量旋转
    {
        double newx, newy;
        newx = x * cos(rad) - y * sin(rad), newy = x * sin(rad) + y * cos(rad);
        return point(newx, newy);
    }
};
double cross(point a, point b)
{
    return a.x * b.y - a.y * b.x;
}
void solve()
{
    double xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    if (sgn(ya - yb) == 0)
    {
        double s = 0.5 * abs(xa - xb) * abs(ya);
        if (sgn(s - 2.0) == 0)
        {
            cout << "0\n";
        }
        else
        {
            cout << "no answer\n";
        }
        return;
    }
    point a(xa, ya), b(xb, yb);
    double s1 = cross(a, b);
    double d = ya - yb;
    double x = (4.0 - s1) / d;
    cout << fixed << setprecision(10) << x << '\n';
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