#include <bits/stdc++.h>
#define int long long
using namespace std;

using u64 = unsigned long long;
using u128 = __uint128_t;
const int N = 2e5;
vector<u64> P(N + 1), nP(N + 1);
namespace Hash
{
    const u64 MOD = (1ULL << 61) - 1;
    const u64 B = chrono::steady_clock::now().time_since_epoch().count() | 1;

    inline u64 mul(u64 a, u64 b)
    {
        return (u64)((u128)a * b % MOD);
    }

    inline u64 add(u64 a, u64 b)
    {
        a += b;
        if (a >= MOD)
            a -= MOD;
        return a;
    }
    inline u64 sub(u64 a, u64 b)
    {
        if (a < b)
            a += MOD;
        a -= b;
        return a;
    }
    inline u64 power(u64 a, u64 b)
    {
        u64 res = 1;
        while (b)
        {
            if (b & 1)
                res = mul(res, a);
            a = mul(a, a);
            b >>= 1;
        }
        return res;
    }
    inline u64 get(u64 x)
    {
        return power(B, x);
    }
    inline u64 get_neg(u64 x)
    {
        return power(B, MOD - 1 - x);
    }
}
void init()
{
    nP[0] = P[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        P[i] = Hash::mul(Hash::B, P[i - 1]);
    }
    nP[N] = Hash::get_neg(N);
    for (int i = N - 1; i >= 1; i--)
    {
        nP[i] = Hash::mul(Hash::B, nP[i + 1]);
    }
}
struct Info
{
    int sum;
    u64 h1, h2;
    int size;
    Info() : sum(0), h1(0), h2(0), size(0) {};
    Info(int value) : sum(value), h1(P[value]), h2(nP[value]), size(1) {};
    Info operator+(const Info &other) const
    {
        Info res;
        res.sum = sum + other.sum;
        res.h1 = Hash::add(h1, other.h1);
        res.h2 = Hash::add(h2, other.h2);
        res.size = size + other.size;
        return res;
    }
};
struct SegTree
{
    int n;
    vector<int> tag, tag1, tag2;
    vector<Info> info;
    SegTree(int _n) : n(_n), tag(4 * _n), info(4 * n), tag1(4 * _n, 1), tag2(4 * _n, 1) {};
    void pull(int p) // 更新上移
    {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    void add(int p, int v, u64 v1, u64 v2)
    {
        tag[p] += v;
        tag1[p] = Hash::mul(tag1[p], v1);
        tag2[p] = Hash::mul(tag2[p], v2);

        info[p].sum += v * info[p].size;
        info[p].h1 = Hash::mul(info[p].h1, v1);
        info[p].h2 = Hash::mul(info[p].h2, v2);
    }
    void push(int p) // 懒标记下放
    {
        if (!tag[p])
            return;
        add(p << 1, tag[p], tag1[p], tag2[p]);
        add(p << 1 | 1, tag[p], tag1[p], tag2[p]);
        tag[p] = 0;
        tag1[p] = 1;
        tag2[p] = 1;
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
        push(p);
        return query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid, r, x, y);
    };
    Info query(int x, int y)
    {
        return query(1, 0, n, x, y);
    };
    // 区间修改[x,y)
    void rangeAdd(int p, int l, int r, int x, int y, int v)
    {
        if (l >= y || r <= x)
            return;
        if (l >= x && r <= y)
        {
            return add(p, v, P[v], nP[v]);
        }
        int mid = l + r >> 1;
        push(p);
        rangeAdd(p << 1, l, mid, x, y, v);
        rangeAdd(p << 1 | 1, mid, r, x, y, v);
        pull(p);
    };
    void rangeAdd(int x, int y, int v)
    {
        rangeAdd(1, 0, n, x, y, v);
    }
    // 单点修改
    void modify(int p, int l, int r, int x, const Info &v)
    {
        if (r - l == 1)
        {
            info[p] = v;
            return;
        }
        int mid = l + r >> 1;
        push(p);
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    SegTree t(n);
    for (int i = 0; i < n; i++)
    {
        t.modify(i, a[i]);
    }
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            l--, r--;
            t.rangeAdd(l, r + 1, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            auto info = t.query(l, r + 1);
            int sum = info.sum;
            if (sum * 2 % (r - l + 1) != 0)
            {
                cout << "NO\n";
                continue;
            }
            sum = sum * 2 / (r - l + 1);
            u64 d = Hash::get(sum);
            if (info.h1 == Hash::mul(d, info.h2))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    init();
    // cin >> t;
    while (t--)
        solve();
    return 0;
}