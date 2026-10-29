// gen2.cpp —— 第二题的数据生成器
// 用法: gen2 <mode> <seed> [参数...]      数据写到 stdout
//   所有模式都保证 1 <= n <= 1e9、0 <= k <= 1e9（n(n+1)/2 <= 5e17，64 位整数不会溢出）。
//   mode 1 <t> <maxn>          随机：n ∈ [1,maxn]，k ∈ [0,n+2]
//   mode 2 <t> <n>             固定 n，k 在 [0,n+2] 内随机
//   mode 3 <t>                 n ∈ [1,1e9]、k ∈ [0,1e9] 随机
//   mode 4 <t>                 边界构造：n ≡ 0,1,2,3 (mod 4)，k ∈ {0,1,2,n-2,n-1,n,n+1,n+2} 附近
//   mode 5                     穷举小数据：n = 1..12，每个 n 枚举 k = 0..n+2（给暴力对拍用）
//   mode 6 <t> <maxn>          只在 n 附近取 k：k ∈ {n-3..n+3}，用于卡结论边界
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

static const ll LIM = 1000000000LL; // n、k 的上界（保证不爆 64 位）

static ull s;
static inline ull nx()
{
    s += 0x9E3779B97F4A7C15ULL;
    ull z = s;
    z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
    z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;
    return z ^ (z >> 31);
}
static inline ll rnd(ll l, ll r)
{
    if (r > l)
        return l + (ll)(nx() % (ull)(r - l + 1));
    return l;
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "usage: gen2 <mode> <seed> [args...]\n");
        return 1;
    }
    int mode = atoi(argv[1]);
    s = strtoull(argv[2], 0, 10) * 0x2545F4914F6CDD1DULL + 99991;
    auto A = [&](int i, ll d) -> ll
    { return argc > i ? atoll(argv[i]) : d; };
    vector<pair<ll, ll>> qs;

    if (mode == 1)
    {
        ll t = A(3, 10), mx = min(A(4, 20), LIM - 3); // 留出 n+2 的余量
        for (ll i = 0; i < t; i++)
        {
            ll n = rnd(1, mx);
            ll k = rnd(0, n + 2);
            qs.push_back({n, k});
        }
    }
    else if (mode == 2)
    {
        ll t = A(3, 10), n = min(A(4, 10), LIM), hi = min(n + 2, LIM);
        for (ll i = 0; i < t; i++)
            qs.push_back({n, rnd(0, hi)});
    }
    else if (mode == 3)
    {
        ll t = A(3, 100000);
        for (ll i = 0; i < t; i++)
        {
            ll n = rnd(1, LIM);
            ll k = rnd(0, LIM);
            qs.push_back({n, k});
        }
    }
    else if (mode == 4)
    {
        ll t = A(3, 1000);
        ll n = rnd(1, LIM - 3);
        while ((ll)qs.size() < t)
        {
            for (int r = 0; r < 4 && (ll)qs.size() < t; r++)
            {
                ll nn = n - (n % 4) + r;
                if (nn < 1)
                    nn += 4;
                if (nn > LIM)
                    nn -= 4;
                ll cand[8] = {0, 1, 2, nn - 2, nn - 1, nn, nn + 1, nn + 2};
                for (int j = 0; j < 8 && (ll)qs.size() < t; j++)
                    if (cand[j] >= 0 && cand[j] <= LIM)
                        qs.push_back({nn, cand[j]});
            }
            n = rnd(1, LIM - 3);
        }
    }
    else if (mode == 5)
    {
        for (int n = 1; n <= 12; n++)
            for (int k = 0; k <= n + 2; k++)
                qs.push_back({n, k});
    }
    else if (mode == 6)
    {
        ll t = A(3, 100000), mx = min(A(4, LIM), LIM - 3);
        for (ll i = 0; i < t; i++)
        {
            ll n = rnd(1, mx);
            ll k = max(0LL, n + rnd(-3, 3));
            qs.push_back({n, min(k, LIM)});
        }
    }
    else
    {
        fprintf(stderr, "unknown mode %d\n", mode);
        return 1;
    }

    // 兜底：无论哪个模式，都保证 1 <= n <= 1e9、0 <= k <= 1e9
    for (auto &pr : qs)
    {
        pr.first = max(1LL, min(pr.first, LIM));
        pr.second = max(0LL, min(pr.second, LIM));
    }

    string out;
    out.reserve(qs.size() * 40);
    out += to_string(qs.size()) + "\n";
    for (auto &pr : qs)
        out += to_string(pr.first) + " " + to_string(pr.second) + "\n";
    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}
