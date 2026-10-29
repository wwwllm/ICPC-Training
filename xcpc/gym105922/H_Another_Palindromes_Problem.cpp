#include <bits/stdc++.h>
#define int long long
using namespace std;
using u64 = unsigned long long;
using u128 = __uint128_t;

// https://codeforces.com/gym/105922
const int inf = 1e9;
namespace Hash
{
    const u64 MOD = (1ULL << 61) - 1;
    const u64 B = chrono::steady_clock::now().time_since_epoch().count() | 1;

    // 安全乘法
    inline u64 mul(u64 a, u64 b)
    {
        return (u64)((u128)a * b % MOD);
    }

    // 安全加法 (替代 C++ 原生的 +)
    inline u64 add(u64 a, u64 b)
    {
        a += b;
        if (a >= MOD)
            a -= MOD;
        return a;
    }

    // 安全减法 (替代 C++ 原生的 -，计算相反数用 sub(0, x))
    inline u64 sub(u64 a, u64 b)
    {
        if (a < b)
            a += MOD;
        a -= b;
        return a;
    }

    // 快速幂
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

    // 求数值 x 的哈希值 B^x % MOD
    inline u64 get(u64 x)
    {
        return power(B, x);
    }
}
struct Info
{
    u64 sum;
    Info() : sum() {};
    Info(u64 value) : sum(value) {};
    Info operator+(const Info &other) const
    {
        return Info(Hash::add(sum, other.sum));
    }
};
struct SegTree
{
    int n;
    vector<u64> tag;
    vector<Info> info;
    SegTree(int _n) : n(_n), tag(4 * _n, 1), info(4 * n) {};
    void pull(int p) // 更新上移
    {
        info[p] = info[p << 1] + info[p << 1 | 1];
    }
    void mul(int p, u64 v)
    {
        tag[p] = Hash::mul(tag[p], v);
        info[p].sum = Hash::mul(info[p].sum, v);
    }
    void push(int p) // 懒标记下放
    {
        mul(p << 1, tag[p]);
        mul(p << 1 | 1, tag[p]);
        tag[p] = 1;
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
    void rangeMul(int p, int l, int r, int x, int y, u64 v)
    {
        if (l >= y || r <= x)
            return;
        if (l >= x && r <= y)
        {
            return mul(p, v);
        }
        int mid = l + r >> 1;
        push(p);
        rangeMul(p << 1, l, mid, x, y, v);
        rangeMul(p << 1 | 1, mid, r, x, y, v);
        pull(p);
    };
    void rangeMul(int x, int y, int v)
    {
        rangeMul(1, 0, n, x, y, Hash::get(v));
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
    SegTree T(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (!(i & 1))
            T.modify(i, Hash::sub(0, Hash::get(x)));
        else
            T.modify(i, Hash::get(x));
    }
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 0)
        {
            int l, r, v;
            cin >> l >> r >> v;
            T.rangeMul(l, r + 1, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            if (T.query(l, r + 1).sum == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
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