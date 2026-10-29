#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
struct Info
{
    int sum;
    Info() : sum() {};
    Info(int value) : sum(value) {};
    Info operator+(const Info &other) const
    {
        Info res;
        res.sum = sum + other.sum;
        return res;
    }
};
struct SegTree
{
    int n;
    vector<Info> info;
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
    void modify(int x, int v)
    {
        modify(1, 0, n, x, Info(v));
    }
};
void solve()
{
    int n;
    cin >> n;
    int m = (n + 1) / 2;
    vector<int> vis(n + 1);
    vector<int> mid;
    for (int i = 0; i < n + m; i++)
    {
        int x;
        cin >> x;
        if (vis[x])
            mid.push_back(x);
        vis[x] = 1;
    }
    auto f = [&](int x) -> int
    {
        return min(x - 1, n - x);
    };
    ranges::sort(mid, [&](int x, int y)
                 { return f(x) < f(y); });
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        s.insert(i);
    }
    if (mid.size() != m)
    {
        cout << -1 << '\n';
        return;
    }
    vector<int> ans;
    vis.assign(n + 1, 0);
    SegTree t(n + 1);

    auto push = [&](int x)
    {
        s.erase(x);
        ans.push_back(x);
        vis[x] = 1;
        t.modify(x, 1);
    };
    push(mid[0]);
    for (int i = 1; i < m; i++)
    {
        int u = mid[i];
        int lcnt = i - t.query(0, u).sum;
        int rcnt = i - t.query(u + 1, n + 1).sum;
        if (lcnt + rcnt + !vis[u] != 2)
        {
            cout << -1 << '\n';
            return;
        }
        while (lcnt)
        {
            int v = *s.begin();
            if (v >= u)
            {
                cout << -1 << '\n';
                return;
            }
            lcnt--;
            push(v);
        }
        while (rcnt)
        {
            int v = *s.rbegin();
            if (v <= u)
            {
                cout << -1 << '\n';
                return;
            }
            rcnt--;
            push(v);
        }
        if (!vis[u])
        {
            push(u);
        }
    }
    if (ans.size() != n)
    {
        cout << -1 << '\n';
    }
    else
    {
        for (int i = 0; i < n; i++)
            cout << ans[i] << " \n"[i == n - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}