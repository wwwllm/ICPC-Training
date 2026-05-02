#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
struct Info
{
    int cnt;
    Info() : cnt(0) {};
    Info(int value) : cnt(value) {};
    Info operator+(const Info &other) const
    {
        return Info(cnt + other.cnt);
    }
};
struct SegTree
{
    int n;
    vector<int> tag;
    vector<Info> info;
    SegTree(int _n) : n(_n), tag(4 * _n), info(4 * n) {};
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
    int query(int x, int y)
    {
        return query(1, 0, n, x, y).cnt;
    };

    int rank(int val)
    {
        return query(0, val) + 1;
    }

    // 单点修改:在x上加v
    void modify(int p, int l, int r, int x, int v)
    {
        if (r - l == 1)
        {
            info[p].cnt += v;
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
        modify(1, 0, n, x, v);
    }
};
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    auto calc = [&](int cnt)
    {
        if (cnt < 0)
            return 0LL;
        SegTree T(n + 1);
        int cur = 0, ans = 0;
        for (int l = 1, r = 1; l <= n; l++)
        {
            while (r <= n && cur + T.query(p[r], n + 1) <= cnt)
            {
                cur += T.query(p[r], n + 1);
                T.modify(p[r++], 1);
            }
            ans += r - l;
            T.modify(p[l], -1);
            cur -= T.query(0, p[l]);
        }
        return ans;
    };
    cout << calc(k) - calc(k - 1) << '\n';
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