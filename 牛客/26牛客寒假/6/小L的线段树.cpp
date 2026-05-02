#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int inf = 1e9;
struct Info
{
    bool ok = 0;
    int val = 0;
    Info() : ok(0), val(1) {};
};

struct SegTree
{
    int n;
    vector<Info> info;

    SegTree(int _n) : n(_n), info(4 * _n) {};

    int query(int p, int l, int r, int x, int y)
    {
        if (l > y || r < x)
            return 0;

        if (l >= x && r <= y)
        {
            return info[p].val;
        }
        int ans = 0;
        if (info[p].ok == 0)
            ans = 1;
        int mid = l + r >> 1;

        if (x <= mid)
            ans += query(p << 1, l, mid, x, y);
        if (y > mid)
            ans += query(p << 1 | 1, mid + 1, r, x, y);

        return ans;
    };

    int query(int x, int y)
    {
        return query(1, 1, n, x, y);
    };

    void modify(int p, int l, int r, int x, int y)
    {
        if (l == x && r == y)
        {
            info[p].ok = 1;
            if (l != r)
            {
                info[p].val = info[p << 1].val + info[p << 1 | 1].val;
            }
            return;
        }
        int mid = l + r >> 1;

        if (y <= mid)
            modify(p << 1, l, mid, x, y);
        else
            modify(p << 1 | 1, mid + 1, r, x, y);

        if (info[p].ok == 1)
        {
            info[p].val = info[p << 1].val + info[p << 1 | 1].val;
        }
        else
            info[p].val = 1;
    }

    void modify(int x, int y)
    {
        modify(1, 1, n, x, y);
    }
};

void solve()
{
    int n;
    cin >> n;
    SegTree T(n);
    int q = n;
    while (q--)
    {
        int op;
        cin >> op;
        int l, r;
        cin >> l >> r;
        if (op == 1)
            T.modify(l, r);
        else
            cout << T.query(l, r) << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}