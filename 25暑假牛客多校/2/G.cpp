#include <bits/stdc++.h>
#define int long long
using namespace std;

using i128 = __int128_t;

const long double PI = acosl(-1.0L);
const long double TAU = 2 * PI;

struct point
{
    int x, y;

    point() {};
    point(const int x, const int y) : x(x), y(y) {};

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
        return x == b.x && y == b.y;
    }
};
// 向量点积
int dot(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

// 叉积
int cross(point a, point b)
{
    return a.x * b.y - a.y * b.x;
}

i128 sq(point p)
{
    return (i128)p.x * (i128)p.x + (i128)p.y * (i128)p.y;
}

bool contain(vector<point> &pts, point p)
{
    int cnt = 0, n = pts.size();
    for (int i = 0; i < pts.size(); i++)
    {
        point a = pts[i], b = pts[(i + 1) % n];
        if (cross(b - a, p - a) < 0)
            return 0;
    }
    return 1;
}

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    point p(x, y);
    vector<point> pts(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        pts[i] = point(x, y);
    }
    bool ok = contain(pts, p);
    if (!ok)
    {
        cout << fixed << setprecision(15) << TAU << '\n';
        return;
    }

    i128 L = 0;
    for (int i = 0; i < n; i++)
    {
        i128 tmp = sq(p - pts[i]);
        L = max(L, tmp);
    }

    vector<long double> t;
    for (int i = 0; i < n; i++)
    {
        if (sq(pts[i] - p) == L)
        {
            long double a = atan2l((long double)((pts[i] - p).y), (long double)((pts[i] - p).x));
            if (a < 0)
                a += TAU;
            t.push_back(a);
        }
    }
    sort(t.begin(), t.end());
    long double tau = 0;
    int m = t.size();
    for (int i = 0; i < m - 1; i++)
    {
        long double tmp = t[(i + 1) % m] - t[i];
        tau = max(tau, tmp);
    }
    tau = max(tau, TAU + t.front() - t.back());
    cout << fixed << setprecision(15) << tau << '\n';
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