#include <bits/stdc++.h>
#define int long long
using namespace std;

using u64 = unsigned long long;
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

// 获取一个随机的 64 位整数
u64 get_random()
{
    return rng();
}
using u64 = unsigned long long;
using u128 = __uint128_t;

namespace Hash
{
    const u64 MOD = (1ULL << 61) - 1;
    // 使用高精度时钟生成随机底数，并保证是奇数 (| 1)
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
const int inf = 1e9;
struct Info
{
    u64 sum;
    Info() : sum() {};
    Info(u64 value) : sum(value) {};
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
    void modify(int x, u64 v)
    {
        modify(1, 0, n, x, Info(v));
    }
};
void solve()
{
    int n, q, k;
    cin >> n >> q >> k;
    vector<int> a(n + 1), c(n + 1);
    vector<int> b;
    for (int i = 1; i <= n; i++)
        cin >> a[i], b.push_back(a[i]);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    ranges::sort(b);
    b.erase(unique(b.begin(), b.end()), b.end());
    auto find = [&](int x) -> int
    {
        return ranges::lower_bound(b, x) - b.begin();
    };
    int m = b.size();
    vector<u64> hash_c(k);
    for (int i = 0; i < k - 1; i++)
    {
        hash_c[i] = get_random();
        hash_c.back() -= hash_c[i];
    }
    SegTree t(n + 1);
    for (int i = 1; i <= n; i++)
    {
        u64 hash = hash_c[c[i]] * Hash::get(a[i]);
        t.modify(i, hash);
    }
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int p, x, color;
            cin >> p >> x >> color;
            a[p] = x;
            c[p] = color;

            u64 hash = hash_c[c[p]] * Hash::get(a[p]);
            t.modify(p, hash);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            u64 hash = t.query(l, r + 1).sum;
            if (hash == 0)
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
    cin >> t;
    while (t--)
        solve();
    return 0;
}