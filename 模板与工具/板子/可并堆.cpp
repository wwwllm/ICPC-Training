#include <bits/stdc++.h>
#define int long long
using namespace std;

struct DSU
{
    int n;
    vector<int> f;
    DSU(int n) : n(n), f(n)
    {
        ranges::iota(f, 0);
    }
    int find(int x)
    {
        return f[x] == x ? x : (f[x] = find(f[x]));
    }
};
struct LeftHeap
{
    struct Node
    {
        int val;
        int l, r;
        int dist;
    };
    vector<Node> t;
    LeftHeap()
    {
        t.push_back({0, 0, 0, 0});
    }
    int newNode(int val)
    {
        t.push_back({val, 0, 0, 1});
        return t.size() - 1;
    }
    int merage(int x, int y)
    {
        if (!x || !y)
            return x | y;

        if (t[x].val > t[y].val || (t[x].val == t[y].val && x > y))
            swap(x, y);
        t[x].r = merage(t[x].r, y);

        if (t[t[x].l].dist < t[t[x].r].dist)
            swap(t[x].l, t[x].r);

        t[x].dist = t[t[x].r].dist + 1;

        return x;
    }
    int push(int root, int val)
    {
        return merage(root, newNode(val));
    }

    int pop(int root)
    {
        assert(root != 0);
        return merage(t[root].l, t[root].r);
    }
    bool empty(int root) const
    {
        return root == 0;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    LeftHeap h;
    DSU dsu(n + 1);

    vector<int> vis(n + 1);
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        h.newNode(val);
    }
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y;
            cin >> x >> y;
            if (vis[x] || vis[y])
                continue;

            int rx = dsu.find(x), ry = dsu.find(y);
            if (rx == ry)
                continue;
            int root = h.merage(rx, ry);
            dsu.f[rx] = root;
            dsu.f[ry] = root;
            dsu.f[root] = root;
        }
        else
        {
            int x;
            cin >> x;
            if (vis[x])
            {
                cout << -1 << '\n';
                continue;
            }
            int root = dsu.find(x);
            cout << h.t[root].val << '\n';

            vis[root] = 1;
            int ls = h.t[root].l, rs = h.t[root].r;

            if (ls)
                dsu.f[ls] = ls;
            if (rs)
                dsu.f[rs] = rs;
            int nroot = h.merage(ls, rs);

            if (ls)
                dsu.f[ls] = nroot;
            if (rs)
                dsu.f[rs] = nroot;

            dsu.f[root] = nroot;
            if (nroot)
                dsu.f[nroot] = nroot;
        }
    }
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