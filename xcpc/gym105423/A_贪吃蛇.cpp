#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105423
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

    bool is_zero()
    {
        return x == 0 && y == 0;
    }
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
double dot(Vector a, Vector b)
{
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b)
{
    return a.x * b.y - b.x * a.y;
}
void solve()
{
    int n;
    cin >> n;
    vector<Point> p(n + 1);
    p[0] = {0, 0};
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    vector<Vector> r;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i != j && !(p[i] - p[j]).is_zero())
                r.push_back(p[i] - p[j]);
        }
    }
    if (r.empty())
        r.push_back(Point(1, 0));
    int ans = 0;
    auto check = [&](Vector a, Vector b) -> bool
    { return sign(dot(a, b)) != -1 && sign(cross(a, b)) != -1; };
    vector<int> vis(n + 1, -1);
    auto dfs = [&](auto &&self, int idx, Vector u) -> int
    {
        if (vis[idx] != -1)
            return vis[idx];
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i == idx)
                continue;
            if (check(u, p[i] - p[idx]))
            {
                res = max(res, 1 + self(self, i, u));
            }
        }
        return vis[idx] = res;
    };
    for (auto u : r)
    {
        vis.assign(n + 1, -1);
        ans = max(ans, dfs(dfs, 0, u));
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}