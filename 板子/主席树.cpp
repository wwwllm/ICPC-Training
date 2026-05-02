#include <bits/stdc++.h>
using namespace std;

struct SegTree
{
    struct Node
    {
        int l;
        int r;
        int cnt;
    };
    vector<int> root;
    int tot;
    int n; // 值域
    vector<Node> info;
    SegTree(int n, int nodes, int ver) : n(n), tot(0)
    {
        info.assign(nodes, {0, 0, 0});
        root.assign(ver + 1, 0);
    }
    void pull(int p)
    {
        int l = info[p].l, r = info[p].r;
        info[p].cnt = info[l].cnt + info[r].cnt;
    }

    void modify(int &p, int pre, int l, int r, int x, int v)
    {
        p = ++tot;
        info[p] = info[pre];

        if (r - l == 1)
        {
            info[p].cnt += v;
            return;
        }
        int mid = l + r >> 1;
        if (x < mid)
        {
            modify(info[p].l, info[p].l, l, mid, x, v);
        }
        else
        {
            modify(info[p].r, info[p].r, mid, r, x, v);
        }
        pull(p);
    }
    void modify(int ver, int pre_ver, int x, int v = 1)
    {
        modify(root[ver], root[pre_ver], 0, n, x, v);
    }

    int query_cnt(int L, int R, int l, int r, int x, int y)
    {
        if (l >= y || r <= x)
            return 0;
        if (x <= l && r <= y)
            return info[R].cnt - info[L].cnt;
        int mid = l + r >> 1;
        return query_cnt(info[L].l, info[R].l, l, mid, x, y) + query_cnt(info[L].r, info[R].r, mid, r, x, y);
    }
    int query_cnt(int L, int R, int l, int r)
    {
        return query_cnt(root[L], root[R], 0, n, l, r);
    }
    int query_rank(int L, int R, int x)
    {
        return query_cnt(root[L], root[R], 0, n, 0, x) + 1;
    }
    int kth(int L, int R, int l, int r, int k)
    {
        if (r - l == 1)
            return l;
        int mid = l + r >> 1;

        int cntl = info[info[R].l].cnt - info[info[L].l].cnt;

        if (k <= cntl)
        {
            return kth(info[L].l, info[R].l, l, mid, k);
        }
        else
        {
            return kth(info[L].r, info[R].r, mid, r, k - cntl);
        }
    }
    int kth(int L, int R, int k)
    {
        return kth(root[L], root[R], 0, n, k);
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    SegTree T(1e9, n * 40, n);
    for (int i = 1; i <= n; i++)
    {
        T.modify(i, i - 1, a[i]);
    }
    while (m--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        cout << T.kth(l - 1, r, k) << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}