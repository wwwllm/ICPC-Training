#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105481
const double eps = 1e-9;
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
double get_length(Point a)
{
    return hypot(a.x, a.y);
}
void solve()
{
    int n;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    vector<double> dp(n);
    double res = 0;
    for (int i = 1; i < n; i++)
    {
        double ma = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            ma = max(ma, get_length(p[i] - p[j]));
            dp[i] = max(dp[i], (j == 0 ? 0 : dp[j - 1]) + ma);
        }
        res = max(dp[i], res);
    }
    cout << fixed << setprecision(10) << res << '\n';
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