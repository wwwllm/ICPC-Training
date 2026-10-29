// std1.cpp —— 抽奖（随机化做法标程）
//
// 询问：区间 [l,r] 内是否存在出现次数 cnt_x 满足 cnt_x > p/q*(r-l+1) 的整数 x。
// 做法：随机化。由于保证 p/q >= 1/10，任何合法答案在区间内占比 > 1/10，
//       所以每次询问在 [l,r] 里随机取 300 个位置，漏掉答案的概率 < 0.9^300 < 1e-13。
//       命中的数用「出现位置表 + 二分」在 O(log) 内算出它在区间内的出现次数，
//       如果超过阈值就输出；300 次都没命中就输出 -1。
// 细节：1) 随机种子固定，同样的输入永远得到同样的输出（保证 .out 可复现）；
//       2) 同一个数在一个询问里只统计一次；
//       3) O(1) 剪枝：若该数在全局的出现次数都不够多，则直接跳过；
//       4) 区间很短（<= SCAN）时直接暴力统计，避免小数据出现采样方差。
#include <bits/stdc++.h>
using namespace std;

static const int SAMPLES = 300; // 每个询问的采样次数
static const int SCAN = 64;     // 区间长度 <= SCAN 时直接暴力统计

/* ---------- splitmix64：快且足够随机 ---------- */
static uint64_t rs = 0x9E3779B97F4A7C15ULL;
static inline uint64_t rnd64()
{
    uint64_t z = (rs += 0x9E3779B97F4A7C15ULL);
    z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
    z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;
    return z ^ (z >> 31);
}
static inline uint32_t rnd_below(uint32_t n) // 均匀返回 [0,n)
{
    return (uint32_t)((unsigned __int128)rnd64() * n >> 64);
}

/* ---------- 读入（自动扩容，把 stdin 全部读进内存） ---------- */
static char *ibuf, *ip;
static void readAll()
{
    size_t cap = 1 << 20, got = 0;
    ibuf = (char *)malloc(cap + 1);
    for (;;)
    {
        got += fread(ibuf + got, 1, cap - got, stdin);
        if (got < cap)
            break;
        cap <<= 1;
        ibuf = (char *)realloc(ibuf, cap + 1);
    }
    ibuf[got] = 0;
    ip = ibuf;
}
static inline int64_t readInt()
{
    while (*ip && (*ip < '0' || *ip > '9') && *ip != '-')
        ++ip;
    bool neg = (*ip == '-');
    if (neg)
        ++ip;
    int64_t x = 0;
    while (*ip >= '0' && *ip <= '9')
        x = x * 10 + (*ip++ - '0');
    return neg ? -x : x;
}

int main()
{
    readAll();

    int n, Q;
    n = (int)readInt();
    Q = (int)readInt();
    vector<int> a(n), ys;
    for (int i = 0; i < n; i++)
        a[i] = (int)readInt();
    ys = a;
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    int m = (int)ys.size();

    vector<int> id(n);
    for (int i = 0; i < n; i++)
        id[i] = (int)(lower_bound(ys.begin(), ys.end(), a[i]) - ys.begin());

    // 出现位置表：flat[st[v]..st[v+1]) 是值 v 出现的所有位置（1-indexed，天然递增）
    vector<uint32_t> st(m + 1, 0);
    for (int i = 0; i < n; i++)
        st[id[i] + 1]++;
    for (int v = 0; v < m; v++)
        st[v + 1] += st[v];
    vector<uint32_t> flat(n);
    {
        vector<uint32_t> cur(st.begin(), st.end() - 1);
        for (int i = 0; i < n; i++)
            flat[cur[id[i]]++] = (uint32_t)(i + 1);
    }
    const uint32_t *fl = flat.data(), *ST = st.data();

    vector<int> vis(m, -1), slot(m, 0);
    vector<int> tv, tc; // 短区间暴力用的临时表
    string out;
    out.reserve((size_t)Q * 8);

    for (int qi = 0; qi < Q; qi++)
    {
        uint32_t l, r;
        int64_t p, q;
        l = (uint32_t)readInt();
        r = (uint32_t)readInt();
        p = readInt();
        q = readInt();
        uint32_t len = r - l + 1;
        int64_t need = (int64_t)len * p; // 条件等价于 cnt*q > need
        int ans = -1;

        if (len <= (uint32_t)SCAN)
        {
            tv.clear();
            tc.clear();
            for (uint32_t i = l; i <= r; i++)
            {
                int v = id[i - 1];
                if (vis[v] != qi)
                {
                    vis[v] = qi;
                    slot[v] = (int)tv.size();
                    tv.push_back(v);
                    tc.push_back(1);
                }
                else
                    tc[slot[v]]++;
            }
            for (size_t j = 0; j < tv.size(); j++)
                if ((int64_t)tc[j] * q > need)
                {
                    ans = ys[tv[j]];
                    break;
                }
        }
        else
        {
            for (int t = 0; t < SAMPLES; t++)
            {
                int v = id[l - 1 + rnd_below(len)];
                if (vis[v] == qi)
                    continue;
                vis[v] = qi;
                uint32_t L = ST[v], R = ST[v + 1];
                if ((int64_t)(R - L) * q <= need) // 全局出现次数都不够 → 直接剪掉
                    continue;
                int c = (int)(upper_bound(fl + L, fl + R, r) - lower_bound(fl + L, fl + R, l));
                if ((int64_t)c * q > need)
                {
                    ans = ys[v];
                    break;
                }
            }
        }

        if (ans < 0)
            out += "-1\n";
        else
        {
            out += to_string(ans);
            out += '\n';
        }
    }
    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}
