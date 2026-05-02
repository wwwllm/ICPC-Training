#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SegTree
{
    struct Node
    {
        int l, r;
        int sum;
    };
    vector<int> root;
    int n, m;
    int tot;
    vector<Node> info;
    SegTree(int n, int m, int q) : n(n), m(m)
    {
        tot = 0;
        root.assign(n, 0);
        info.resize(q * 40);
    }
    void pull(int p)
    {
        info[p].sum = info[info[p].l].sum + info[info[p].r].sum;
    }
    void modify(int &p, int pre, int l, int r, int x, int v)
    {
        p = ++tot;
        info[p] = info[pre];
        if (r - l == 1)
        {
            info[p].sum = v;
            return;
        }
        int mid = l + r >> 1;
        if (x < mid)
            modify(info[p].l, info[p].l, l, mid, x, v);
        else
            modify(info[p].r, info[p].r, mid, r, x, v);
        pull(p);
    }
    void modify(int x, int y, int z)
    {
        modify(root[x], root[x], 0, m, y, z);
    }
    int query(int p, int l, int r, int x, int y)
    {
        if (!p || l >= y || r <= x)
            return 0;
        if (l >= x && r <= y)
            return info[p].sum;
        int mid = l + r >> 1;
        return query(info[p].l, l, mid, x, y) + query(info[p].r, mid, r, x, y);
    }
    int query(int idx, int l, int r)
    {
        return query(root[idx], 0, m, l, r);
    };
};
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    SegTree T(n, m, q);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y;
            cin >> x >> y;
            x--, y--;
            T.root[x] = T.root[y];
        }
        else if (op == 2)
        {
            int x, y, z;
            cin >> x >> y >> z;
            x--, y--;
            T.modify(x, y, z);
        }
        else
        {
            int i, l, r;
            cin >> i >> l >> r;
            i--, l--, r--;
            cout << T.query(i, l, r + 1) << '\n';
        }
    }
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