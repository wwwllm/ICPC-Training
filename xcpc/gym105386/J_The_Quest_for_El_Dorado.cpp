#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105386/problem/L
const int inf = 1e9;
struct Info
{
    int max;
    int p;
    Info() : max(-inf), p(0) {};
    Info(int value, int p) : max(value), p(p) {};
    Info operator+(const Info &other) const
    {
        Info res;
        if (max > other.max)
            res = {max, p};
        else if (max == other.max)
            res = {max, std::min(p, other.p)};
        else
            res = {other.max, other.p};
        return res;
    }
};
struct SegTree
{
    int n;
    vector<Info> info;
    SegTree() {};
    SegTree(int _n) : n(_n), info(4 * _n) {};
    void pull(int p) // 更新上移
    {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    // 区间查询[x,y)
    Info query(int p, int l, int r, int x, int y)
    {
        if (l >= y || r <= x)
            return {};
        if (l >= x && r <= y)
        {
            return info[p];
        }
        int mid = l + r >> 1;
        return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid, r, x, y);
    };
    Info query(int x, int y)
    {
        return query(1, 0, n, x, y);
    };
    // 单点修改
    void modify(int p, int l, int r, int x, const Info &v)
    {
        if (r - l == 1)
        {
            info[p] = v;
            return;
        }
        int mid = l + r >> 1;
        if (x < mid)
        {
            modify(p << 1, l, mid, x, v);
        }
        else
        {
            modify(p << 1 | 1, mid, r, x, v);
        }
        pull(p);
    }
    void modify(int x, int v, int p)
    {
        modify(1, 0, n, x, Info(v, p));
    }
};
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector adj(n + 1, vector<array<int, 3>>());
    for (int i = 1; i <= m; i++)
    {
        int u, v, c, l;
        cin >> u >> v >> c >> l;
        adj[u].push_back({v, c, l});
        adj[v].push_back({u, c, l});
    }
    vector<array<int, 2>> dis(n + 1, {inf, inf});
    dis[1] = {0, 0};
    vector color(m + 1, vector<int>());
    vector<array<int, 2>> a(k);
    for (int i = 0; i < k; i++)
    {
        cin >> a[i][0] >> a[i][1];
        color[a[i][0]].push_back(i);
    }
    vector<SegTree> T(m + 1);
    for (int i = 0; i <= m; i++)
    {
        if (color[i].size())
        {
            int sz = color[i].size();
            T[i] = SegTree(sz);
            for (int j = 0; j < sz; j++)
            {
                T[i].modify(j, a[color[i][j]][1], color[i][j]);
            }
        }
    }
    auto find = [&](int c, int p, int len)
    {
        int pos = ranges::upper_bound(color[c], p) - color[c].begin();
        if (pos == color[c].size())
            return pos;
        auto &t = T[c];
        int l = pos - 1, r = color[c].size();
        while (l + 1 != r)
        {
            int mid = l + r >> 1;
            int res = t.query(pos, mid + 1).max;
            if (res >= len)
                r = mid;
            else
                l = mid;
        }
        return r;
    };
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    pq.push({0, 0, 1});
    auto cmp = [&](const array<int, 2> &a, const array<int, 2> &b) -> bool
    {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] > b[0];
    };
    while (pq.size())
    {
        auto [p, d, u] = pq.top();
        pq.pop();
        if (cmp({p, d}, dis[u]))
            continue;
        for (auto [v, c, l] : adj[u])
        {
            array<int, 2> tmp;
            if (a[p][0] == c && d + l <= a[p][1])
            {
                tmp = {p, d + l};
            }
            else
            {
                int pos = find(c, p, l);
                if (pos == color[c].size())
                    tmp = {inf, inf};
                else
                    tmp = {color[c][pos], l};
            }
            if (cmp(dis[v], tmp))
            {
                dis[v] = tmp;
                pq.push({tmp[0], tmp[1], v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] != array<int, 2>{inf, inf})
            cout << 1;
        else
            cout << 0;
    }
    cout << '\n';
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