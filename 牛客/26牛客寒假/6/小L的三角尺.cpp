#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

struct point
{
    int x, y;
    point(int x, int y) : x(x), y(y)
    {
    }
    point() {};
    bool operator<(const point &other) const
    {
        return sqrt(x * x + y * y) - sqrt(x * x + (y - 1) * (y - 1)) < sqrt(other.x * other.x + other.y * other.y) - sqrt(other.x * other.x + (other.y - 1) * (other.y - 1));
    };
};
void solve()
{
    int n, w;
    cin >> n >> w;
    double ans = 0.0;
    vector<point> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    priority_queue<point> pq;
    for (int i = 0; i < n; i++)
        pq.push(p[i]);
    while (w--)
    {
        auto [x, y] = pq.top();
        pq.pop();
        if (y)
            y--;
        pq.push(point(x, y));
    }
    while (pq.size())
    {
        auto [x, y] = pq.top();
        pq.pop();
        ans += sqrt(x * x + y * y);
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