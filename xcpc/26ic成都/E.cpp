#include <bits/stdc++.h>
#define int long long
using namespace std;

using T = int;
int sign(T x)
{
    if (x == 0)
        return 0;
    return x / abs(x);
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

    bool operator<(const Point &b) const
    {
        int c = cmp(x, b.x);
        if (c != 0)
            return c == -1;
        return cmp(y, b.y) == -1;
    }

    T len2() const
    {
        return x * x + y * y;
    }
};
T dot(const Vector &a, const Vector &b)
{
    return a.x * b.x + a.y * b.y;
}
T cross(const Vector &a, const Vector &b)
{
    return a.x * b.y - b.x * a.y;
}
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
struct Segment
{
    Point a, b;
    Segment() {}
    Segment(Point a, Point b) : a(a), b(b) {}
    int on_segment(const Point &p) const
    {
        if (p == a || p == b)
            return -1;
        if (sign(cross(p - a, p - b)) == 0 && sign(dot(p - a, p - b)) <= 0)
            return 1;
        return 0;
    }
};
struct Line
{
    Point p;
    Vector v;
    Line() {}
    Line(Point p, Vector v) : p(p), v(v) {}
    int to_left(const Point &a) const
    {
        return sign(cross(v, a - p));
    }
};
struct Polygon
{
    vector<Point> p;
    Polygon() {}
    Polygon(const vector<Point> &p) : p(p) {}

    int size() const
    {
        return p.size();
    }

    int contain(const Point &a) const
    {
        bool in = false;
        for (int i = 0; i < size(); i++)
        {
            Point u = p[i], v = p[(i + 1) % size()];
            if (Segment(u, v).on_segment(a) != 0)
                return -1;
            if ((u.y > a.y) != (v.y > a.y) &&
                sign(cross(v - u, a - u)) == ((v.y > a.y) > 0 ? 1 : -1))
                in = !in;
        }
        return in ? 1 : 0;
    }
};
struct Convex : Polygon
{
    Convex() {};
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
        bool collinear = true;
        for (int i = 2; i < (int)q.size(); i++)
            if (sign(cross(q[1] - q[0], q[i] - q[0])) != 0)
            {
                collinear = false;
                break;
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
                p.pop_back();
            p.push_back(a);
        }
        int lower_size = p.size();
        for (int i = (int)q.size() - 2; i >= 0; i--)
        {
            while ((int)p.size() > lower_size && check(p[p.size() - 2], p.back(), q[i]))
                p.pop_back();
            p.push_back(q[i]);
        }
        p.pop_back();
    }
};
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<Point> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<Point, int> id;
    for (int i = 0; i < n; i++)
    {
        id[a[i]] = i + 1;
    }
    Convex c(a);
    int m = c.size();
    auto &p = c.p;
    Point o = p[0];
    vector<Vector> v(m);
    for (int i = 1; i < m; i++)
    {
        v[i] = p[i] - o;
    }
    Point ext = o;
    if (m == 4)
    {
        for (auto &pt : a)
            if (Line(p[0], p[2] - p[0]).to_left(pt) != 0 && Line(p[1], p[3] - p[1]).to_left(pt) != 0)
            {
                ext = pt;
                break;
            }
    }
    auto find = [&](Point x) -> int
    {
        int l = 1, r = m;
        while (l + 1 != r)
        {
            int mid = l + r >> 1;
            if (Line(o, v[mid]).to_left(x) != 1)
                r = mid;
            else
                l = mid;
        }
        return r;
    };
    while (q--)
    {
        Point x;
        cin >> x;
        if (m < 3)
        {
            cout << -1 << '\n';
            continue;
        }
        int pos = find(x);
        if (pos == m)
        {
            cout << -1 << '\n';
        }
        else
        {
            Convex tmp({o, p[pos - 1], p[pos]});
            int res = tmp.contain(x);
            if (res == 1)
            {
                cout << 3 << '\n'
                     << id[o] << ' ' << id[p[pos - 1]] << ' ' << id[p[pos]] << '\n';
            }
            else if (res == -1 && pos < m - 1 && Segment(o, p[pos]).on_segment(x) == 1)
            {
                vector<Point> pts = {o, p[pos - 1], p[pos], p[pos + 1]};
                if (m >= 5)
                    pts.push_back(p[pos > 2 ? 1 : 4]);
                else if (!(ext == o))
                    pts.push_back(ext);

                bool ok = 0;
                int sz = pts.size();
                for (int i = 0; i < sz && !ok; i++)
                    for (int j = i + 1; j < sz && !ok; j++)
                        for (int k = j + 1; k < sz && !ok; k++)
                        {
                            tmp = Convex({pts[i], pts[j], pts[k]});
                            if (tmp.size() == 3 && tmp.contain(x) == 1)
                            {
                                cout << 3 << '\n'
                                     << id[pts[i]] << ' ' << id[pts[j]] << ' ' << id[pts[k]] << '\n';
                                ok = 1;
                            }
                        }
                if (!ok)
                {
                    cout << 4 << '\n';
                    for (int i = 0; i < 4; i++)
                        cout << id[c.p[i]] << " \n"[i == 3];
                }
            }
            else
            {
                cout << -1 << '\n';
            }
        }
    }
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