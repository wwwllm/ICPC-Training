#include <bits/stdc++.h>
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
            info[p] = info[p] + v;
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
    int n, m, q;
    cin >> n >> m >> q;
    deque<int> L, R;
    vector<int> time(m, m);
    vector<array<int, 2>> qu(m);
    for (int i = 0; i < m; i++)
    {
        int op, x;
        cin >> op >> x;
        x--;
        if (op == 0)
        {
            while (L.size() && qu[L.back()][1] <= x)
            {
                time[L.back()] = i;
                L.pop_back();
            }
            if (L.size())
            {
                qu[L.back()][0] = max(x + 1, qu[L.back()][0]);
            }
            L.push_back(i);
            qu[i] = {0, x};
            while (R.size() && qu[R.front()][1] <= x)
            {
                time[R.front()] = i;
                R.pop_front();
            }
            if (R.size())
            {
                qu[R.front()][0] = max(qu[R.front()][0], x + 1);
            }
        }
        else
        {
            while (R.size() && qu[R.back()][0] >= x)
            {
                time[R.back()] = i;
                R.pop_back();
            }
            if (R.size())
            {
                qu[R.back()][1] = min(x - 1, qu[R.back()][1]);
            }
            R.push_back(i);
            qu[i] = {x, n - 1};
            while (L.size() && qu[L.front()][0] >= x)
            {
                time[L.front()] = i;
                L.pop_front();
            }
            if (L.size())
            {
                qu[L.front()][1] = min(x - 1, qu[L.front()][1]);
            }
        }
    }
    vector<array<int, 3>> Q(q);
    vector<int> ans(q);
    for (int i = 0; i < q; i++)
    {
        auto &[l, r, id] = Q[i];
        cin >> l >> r;
        l--, r--;
        id = i;
    }
    SegTree t(m + 1);
    ranges::sort(Q, greater<>());
    int cur = m - 1;
    for (auto [l, r, id] : Q)
    {
        // cerr << l << ' ' << r << '\n';
        while (cur >= l)
        {
            int die = time[cur--];
            t.modify(die, 1);
        }
        // cerr << t.query(r + 1, m + 1).sum << '\n';
        ans[id] = t.query(r + 1, m + 1).sum - (m - 1 - r);
    }
    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << '\n';
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