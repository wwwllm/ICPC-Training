// gen1.cpp —— 抽奖 的数据生成器
// 用法: gen1 <mode> <seed> [参数...]        （数据写到 stdout）
//
//  mode 1  <n> <Q> <V>            小数据随机：值域 [1,V]，区间随机，阈值随机（>=1/10）
//  mode 2  <n> <Q>                所有数互不相同 → 几乎全是 -1
//  mode 3  <n> <Q> <D> <L1> <L2>  循环 D 个值（a[i]=i%D+1），区间长度 ∈ [L1,L2]
//                                 D=11 且 L1>=110 时保证答案全是 -1
//  mode 4  <n> <Q> <num> <den>    每段区间内造一个「刚好超过阈值」的唯一答案：
//                                 cnt = floor(len*num/den)+1，其余位置放全局唯一值 → 答案唯一
//                                 要求 Q*den/num <= n（区间两两不重叠）
//  mode 5  <n> <Q> <num> <den>    同上但 cnt = floor(len*num/den)：恰好卡在阈值上 → 保证全是 -1
//                                 （专门杀用 >= 判断的假做法）
//  mode 6  <n> <Q> <D> <L>        对抗性：D 个值各出现 n/D 次，区间长度固定 L（压随机化做法的速度）
//  mode 7  <n> <Q>                所有询问都是 [1,n]
//  mode 8  <n> <Q>                所有询问都是单点 [i,i]
//  mode 9  <n> <Q> <num> <den>    每个区间内恰好只有一个数满足条件，其余全是「一次性」的值（压采样次数）
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

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

int n, Q;
vector<int> a;
vector<array<ll, 4>> qs;

static void put()
{
    string o;
    o.reserve((size_t)n * 12 + (size_t)Q * 48);
    o += to_string(n) + " " + to_string(Q) + "\n";
    for (int i = 0; i < n; i++)
        o += to_string(a[i]) + (i + 1 == n ? '\n' : ' ');
    for (auto &qr : qs)
        o += to_string(qr[0]) + " " + to_string(qr[1]) + " " + to_string(qr[2]) + " " + to_string(qr[3]) + "\n";
    fwrite(o.data(), 1, o.size(), stdout);
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "usage: gen1 <mode> <seed> [args...]\n");
        return 1;
    }
    int mode = atoi(argv[1]);
    s = strtoull(argv[2], 0, 10) * 0x2545F4914F6CDD1DULL + 0x1234567ULL;
    auto A = [&](int i, ll d) -> ll
    { return argc > i ? atoll(argv[i]) : d; };

    // 随机取一个 >= 1/10 的分数
    auto frac = [&](ll &num, ll &den)
    {
        static const ll nu[] = {1, 1, 1, 1, 1, 2, 3, 1, 1};
        static const ll de[] = {10, 10, 10, 9, 8, 5, 10, 5, 4};
        int k = (int)rnd(0, 8);
        num = nu[k], den = de[k];
    };

    if (mode == 1)
    {
        n = (int)A(3, 10), Q = (int)A(4, 10);
        ll V = A(5, 5);
        a.resize(n);
        for (int i = 0; i < n; i++)
            a[i] = (int)rnd(1, V);
        for (int i = 0; i < Q; i++)
        {
            ll l = rnd(1, n), r = rnd(1, n);
            if (l > r)
                swap(l, r);
            ll p, q;
            frac(p, q);
            qs.push_back({l, r, p, q});
        }
    }
    else if (mode == 2)
    {
        n = (int)A(3, 100), Q = (int)A(4, 100);
        a.resize(n);
        vector<int> perm(n);
        for (int i = 0; i < n; i++)
            perm[i] = i + 1;
        for (int i = n - 1; i > 0; i--)
            swap(perm[i], perm[(size_t)rnd(0, i)]);
        for (int i = 0; i < n; i++)
            a[i] = (int)((ll)perm[i] * 7919 % 1000000000LL + 1);
        for (int i = 0; i < Q; i++)
        {
            ll l = rnd(1, n), r = rnd(1, n);
            if (l > r)
                swap(l, r);
            ll p, q;
            frac(p, q);
            qs.push_back({l, r, p, q});
        }
    }
    else if (mode == 3)
    {
        n = (int)A(3, 100), Q = (int)A(4, 100);
        ll D = max(2LL, A(5, 11)), L1 = min<ll>(n, A(6, 1)), L2 = min<ll>(n, A(7, n));
        a.resize(n);
        for (int i = 0; i < n; i++)
            a[i] = (int)(i % D) + 1;
        for (int i = 0; i < Q; i++)
        {
            ll len = rnd(max(1LL, min(L1, L2)), max(L1, L2));
            ll l = rnd(1, n - len + 1);
            qs.push_back({l, l + len - 1, 1, 10});
        }
    }
    else if (mode == 4 || mode == 5)
    {
        ll num = A(3, 1), den = A(4, 10);
        if (num == den)
            den = num + 1; // 保证阈值 < 1
        ll minlen = (den + num - 1) / num; // 使 floor(len*num/den) >= 1
        n = (int)A(5, 100000);
        Q = (int)min<ll>(A(6, 10000), n / max(1LL, minlen));
        a.assign(n, 0);
        // 填充值：1..n 的随机排列（全局唯一，因此任意区间内只出现一次）
        vector<int> perm(n);
        for (int i = 0; i < n; i++)
            perm[i] = i + 1;
        for (int i = n - 1; i > 0; i--)
            swap(perm[i], perm[(size_t)rnd(0, i)]);
        for (int i = 0; i < n; i++)
            a[i] = perm[i];
        // 把 [1,n] 切成 Q 段（每段长度 >= minlen），段内造众数
        vector<int> cut;
        cut.push_back(1);
        for (int i = 1; i < Q; i++)
            cut.push_back((int)(1 + (ll)i * n / Q));
        cut.push_back(n + 1); // 共 Q+1 个端点
        for (int i = 0; i < Q; i++)
        {
            int l = cut[i], r = cut[i + 1] - 1;
            ll len = r - l + 1;
            ll cnt = len * num / den + (mode == 4 ? 1 : 0); // mode4: 刚好超过；mode5: 恰好等于/不足
            int x = (int)(1000000000LL - i);                // 全局唯一的值
            vector<int> pos(len);
            for (ll j = 0; j < len; j++)
                pos[j] = (int)(l + j);
            for (ll j = len - 1; j > 0; j--)
                swap(pos[j], pos[(size_t)rnd(0, j)]);
            for (ll j = 0; j < cnt && j < len; j++)
                a[pos[j] - 1] = x;
            qs.push_back({l, r, num, den});
        }
    }
    else if (mode == 6)
    {
        n = (int)A(3, 100000), Q = (int)A(4, 100000);
        ll D = max(2LL, A(5, 300)), L = min<ll>(n, A(6, n / 50));
        a.resize(n);
        for (int i = 0; i < n; i++)
            a[i] = (int)(i % D) + 1;
        for (int i = 0; i < Q; i++)
        {
            ll l = rnd(1, n - L + 1);
            qs.push_back({l, l + L - 1, 1, 10});
        }
    }
    else if (mode == 7)
    {
        n = (int)A(3, 100), Q = (int)A(4, 100);
        a.resize(n);
        for (int i = 0; i < n; i++)
            a[i] = (int)rnd(1, max(1LL, (ll)n / 10));
        for (int i = 0; i < Q; i++)
        {
            ll p, q;
            frac(p, q);
            qs.push_back({1, n, p, q});
        }
    }
    else if (mode == 8)
    {
        n = (int)A(3, 100), Q = (int)A(4, 100);
        a.resize(n);
        for (int i = 0; i < n; i++)
            a[i] = (int)rnd(1, 1000000000LL);
        for (int i = 0; i < Q; i++)
        {
            ll x = rnd(1, n);
            ll p, q;
            frac(p, q);
            qs.push_back({x, x, p, q});
        }
    }
    else if (mode == 9)
    {
        // 唯一的答案出现次数刚好超过阈值，其余位置全是全局唯一的值 → 采样次数不够就会漏
        ll num = A(3, 1), den = A(4, 10);
        n = (int)A(5, 100000);
        Q = (int)A(6, 100000);
        a.assign(n, 0);
        vector<int> perm(n);
        for (int i = 0; i < n; i++)
            perm[i] = i + 1;
        for (int i = n - 1; i > 0; i--)
            swap(perm[i], perm[(size_t)rnd(0, i)]);
        for (int i = 0; i < n; i++)
            a[i] = perm[i];
        for (int i = 0; i < Q; i++)
        {
            ll len = rnd(n / 2, n);
            ll l = rnd(1, n - len + 1), r = l + len - 1;
            ll cnt = len * num / den + 1;
            int x = (int)(1000000000LL - (i % n));
            vector<int> pos(len);
            for (ll j = 0; j < len; j++)
                pos[j] = (int)(l + j);
            for (ll j = len - 1; j > 0; j--)
                swap(pos[j], pos[(size_t)rnd(0, j)]);
            for (ll j = 0; j < cnt; j++)
                a[pos[j] - 1] = x;
            qs.push_back({l, r, num, den});
        }
    }
    else
    {
        fprintf(stderr, "unknown mode %d\n", mode);
        return 1;
    }
    put();
    return 0;
}
