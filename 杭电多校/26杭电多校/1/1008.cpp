#include <bits/stdc++.h>
using namespace std;

// const int inf = 1e9, N = 5e6;
// struct Info
// {
//     int max;
//     Info() : max(-inf) {};
//     Info(int value) : max(value) {};
//     Info operator+(const Info &other) const
//     {
//         Info res;
//         res.max = std::max(max, other.max);
//         return res;
//     }
// };
// struct SegTree
// {
//     int n;
//     vector<Info> info;
//     SegTree(int _n) : n(_n), info(4 * _n) {};
//     void pull(int p) // 更新上移
//     {
//         info[p] = info[p << 1] + info[p << 1 | 1];
//     }
//     // 区间查询[x,y)
//     Info query(int p, int l, int r, int x, int y)
//     {
//         if (l >= y || r <= x)
//             return {};
//         if (l >= x && r <= y)
//         {
//             return info[p];
//         }
//         int mid = l + r >> 1;
//         return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid, r, x, y);
//     };
//     Info query(int x, int y)
//     {
//         return query(1, 0, n, x, y);
//     };
//     // 单点修改
//     void modify(int p, int l, int r, int x, const Info &v)
//     {
//         if (r - l == 1)
//         {
//             info[p] = info[p] + v;
//             return;
//         }
//         int mid = l + r >> 1;
//         if (x < mid)
//         {
//             modify(p << 1, l, mid, x, v);
//         }
//         else
//         {
//             modify(p << 1 | 1, mid, r, x, v);
//         }
//         pull(p);
//     }
//     void modify(int x, int v)
//     {
//         modify(1, 0, n, x, Info(v));
//     }
// };

struct Fenwick
{
    int n;
    vector<int> info;

    Fenwick(int _n) : n(_n), info(_n + 1) {}

    void clear(int _n)
    {
        n = _n;
        fill(info.begin(), info.begin() + n + 1, 0);
    }

    // 单点取 max
    void modify(int x, int v)
    {
        for (; x <= n; x += x & -x)
        {
            info[x] = max(info[x], v);
        }
    }

    // 查询 [1, x] 最大值
    int query(int x)
    {
        int res = 0;
        for (; x > 0; x -= x & -x)
        {
            res = max(res, info[x]);
        }
        return res;
    }
};
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    vector<int> dp(n + 1);
    vector<int> g(n + 1);
    int ans = 0;
    vector<int> pos(n + 1);
    vector<int> ndp(n + 1, 0);
    vector<int> t(10);
    for (int l = 1; l * (l + 1) / 2 <= n; l++)
    {
        auto check = [&](int e) -> bool
        {
            int st = e - l + 1;
            if (st < 1)
                return 0;
            return l == 1 || s[st] != '0';
        };
        int m = t.back() * 10 + 10;
        t.assign(m, 0);
        for (int i = l; i <= n; i++)
        {
            if (check(i))
            {
                t[pos[i - 1] * 10 + (s[i] - '0')] |= 1;
            }
        }
        for (int i = 1; i < m; i++)
        {
            t[i] += t[i - 1];
        }
        for (int i = n; i >= 1; i--)
        {
            if (check(i))
            {
                pos[i] = t[pos[i - 1] * 10 + (s[i] - '0')];
            }
            else
                pos[i] = 0;
        }
        m = t.back() + 1;
        Fenwick T(m + 1);

        ndp.assign(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            int j = i - l;
            if (j < 0)
                continue;
            if (j >= l && pos[j] != 0 && ndp[j] != 0)
            {
                T.modify(pos[j], ndp[j]);
            }
            if (pos[i] == 0)
                continue;
            ndp[i] = max(ndp[i], g[j] + 1);
            ndp[i] = max(ndp[i], T.query(pos[i] - 1) + 1);
            ans = max(ndp[i], ans);
        }
        for (int i = 1; i <= n; i++)
        {
            g[i] = max({ndp[i], g[i], g[i - 1]});
        }
        dp = ndp;
    }
    cout << ans << '\n';
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