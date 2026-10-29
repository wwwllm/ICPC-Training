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
    int n, x;
    cin >> n >> x;
    x--;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
        q[i]--;
    }
    vector<int> ans;
    vector<int> posp(n), posq(n);
    for (int i = 0; i < n; i++)
    {
        posp[p[i]] = i;
        posq[q[i]] = i;
    }
    SegTree tp(n), tq(n);
    for (int i = 0; i < n; i++)
    {
        tp.modify(i, 1);
        tq.modify(i, 1);
    }
    int i = 0, j = 0;
    vector<int> vis(n);
    bool ok = 1;
    auto Erase = [&](int u)
    {
        tp.modify(posp[u], 0);
        tq.modify(posq[u], 0);
        vis[u] = 1;
        ans.push_back(u);
    };
    while (ans.size() < n - 1)
    {
        while (i < n && vis[p[i]])
            i++;
        while (j < n && vis[q[j]])
            j++;
        if (i == n || j == n)
            break;
        int u = p[i], v = q[j];
        if (v == u && (u != x))
            break;
        if (u == v && u == x)
            break;
        int iu = tq.query(0, posq[u] + 1).sum, iv = tp.query(0, posp[v] + 1).sum;
        if (u == x)
        {
            Erase(v);
            continue;
        }
        if (v == x)
        {
            Erase(u);
            continue;
        }
        if (iu < iv)
        {
            Erase(u);
        }
        else
        {
            Erase(v);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0 && i != x)
            ok = 0;
    }
    if (!ok)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (auto u : ans)
    {
        cout << u + 1 << ' ';
    }
    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}