#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
struct Info
{
    int max;
    int size = 0;
    Info() : max(-inf), size(0) {};
    Info(int value) : max(value), size(1) {};
    Info operator+(const Info &other) const
    {
        Info res;
        res.max = std::max(max, other.max);
        res.size = size + other.size;
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
    void modify(int x, Info v)
    {
        modify(1, 0, n, x, v);
    }
};
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n + 1), pos(n + 1), b(m + 1);
    vector<int> keep(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        keep[b[i]] = 1;
    }

    multiset<int> len;

    for (int i = 0; i < k; i++)
    {
        int l;
        cin >> l;
        len.insert(l);
    }

    for (int i = 1; i <= n; i++)
        pos[a[i]] = i;

    for (int i = 2; i <= m; i++)
    {
        if (pos[b[i - 1]] > pos[b[i]])
        {
            cout << "NO\n";
            return;
        }
    }

    SegTree t(n + 1);

    for (int i = 1; i <= n; i++)
        t.modify(i, Info(a[i]));

    set<int> s;

    s.insert(0);
    s.insert(n + 1);

    for (int x = n; x >= 1; x--)
    {
        if (keep[x])
        {
            s.insert(pos[x]);
        }
        else
        {
            int idx = pos[x];

            auto it = s.lower_bound(idx);

            int R = *it;
            int L = *prev(it);

            int sz = t.query(L + 1, R).size;
            auto p = len.upper_bound(sz);
            if (p == len.begin())
            {
                cout << "NO\n";
                return;
            }
            p--;
            len.erase(p);
            t.modify(idx, Info());
        }
    }

    cout << "YES\n";
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