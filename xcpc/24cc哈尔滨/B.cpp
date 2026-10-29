#include <bits/stdc++.h>
#define int long long
using namespace std;

const double eps = 1e-9;
const int inf = 4e18;
using T = int;
int sign(T x)
{
    if (x == 0)
        return 0;
    return x < 0 ? -1 : 1;
}
int cmp(T x, T y)
{
    return sign(x - y);
}
struct Point;
using Vector = Point;

struct Point
{
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {};
    Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
    Point operator*(const T k) const { return Point(x * k, y * k); }
    Point operator/(const T k) const { return Point(x / k, y / k); }

    friend istream &operator>>(istream &in, Point &p)
    {
        in >> p.x >> p.y;
        return in;
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
    T len2() const { return x * x + y * y; }
};
T dot(const Vector &a, const Vector &b) { return a.x * b.x + a.y * b.y; }
T cross(const Vector &a, const Vector &b) { return a.x * b.y - a.y * b.x; }

T area(const Point &a, const Point &b, const Point &c) { return cross(b - a, c - a); }

bool is_collinear(const Point &a, const Point &b, const Point &c) { return sign(cross(b - a, c - a)) == 0; }

Point reflect(const Point &o, const Point &p) { return o * 2 - p; }

struct Polarcmp
{
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

    bool operator()(const Point &a, const Point &b) const
    {
        int qa = quad(a), qb = quad(b);
        if (qa != qb)
            return qa < qb;
        T c = cross(a, b);
        if (sign(c) != 0)
            return sign(c) > 0;
        return a.len2() < b.len2();
    }
};
struct Polygon
{
    vector<Point> p;
    Polygon() {};
    Polygon(const vector<Point> &p) : p(p) {};
    int size() const { return p.size(); }
    T area2() const
    {
        T res = 0;
        for (int i = 0; i < size(); i++)
        {
            res += cross(p[i], p[(i + 1) % size()]);
        }
        return res;
    }
};

struct Convex : Polygon
{
    Convex() {}
    Convex(vector<Point> q, bool keep_collinear = false)
    {
        build(q, keep_collinear);
    }
    void build(vector<Point> q, bool keep_collinear = false)
    {
        sort(q.begin(), q.end());
        q.erase(unique(q.begin(), q.end()), q.end());
        p.clear();
        if (q.size() <= 1)
        {
            p = q;
            return;
        }
        bool collinear = 1;
        for (int i = 2; i <= q.size(); i++)
        {
            if (sign(cross(q[1] - q[0], q[i] - q[0])) != 0)
            {
                collinear = 0;
                break;
            }
        }
        if (collinear)
        {
            p = keep_collinear ? q : vector<Point>{q.front(), q.back()};
            return;
        }
        auto check = [&](const Point &a, const Point &b, const Point &c)
        {
            int s = sign(cross(b - a, c - b));
            return keep_collinear ? s < 0 : s <= 0;
        };

        for (const Point &a : q)
        {
            while (p.size() >= 2 && check(p[p.size() - 2], p.back(), a))
            {
                p.pop_back();
            }
            p.push_back(a);
        }
        int lower_size = p.size();
        for (int i = q.size() - 2; i >= 0; i--)
        {
            while (p.size() > lower_size && check(p[p.size() - 2], p.back(), q[i]))
                p.pop_back();
            p.push_back(q[i]);
        }
        p.pop_back();
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<Point> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Convex C1(a, 1), C2;
    {
        set<Point> tmp;
        for (auto p : C1.p)
        {
            tmp.insert(p);
        }
        vector<Point> q;
        for (int i = 0; i < n; i++)
        {
            if (tmp.count(a[i]))
                continue;
            q.push_back(a[i]);
        }
        if (q.empty())
        {
            cout << "-1\n";
            return;
        }
        C2.build(q, 1);
    }
    n = C1.size();
    int m = C2.size();
    int sum = C1.area2();
    int d = inf;
    for (int i = 0, j = 0; i < n; i++)
    {
        auto u = C1.p[i], v = C1.p[(i + 1) % n];
        while (area(u, v, C2.p[j]) > area(u, v, C2.p[(j + 1) % m]))
        {
            (j += 1) %= m;
        }
        d = min(d, area(u, v, C2.p[j]));
    }
    // cerr << sum << ' ' << d << '\n';
    cout << sum - d << '\n';
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