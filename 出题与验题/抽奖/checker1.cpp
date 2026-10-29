// checker1.cpp —— 抽奖 的 Special Judge（独立校验器，不依赖标程的 .out）
//
// 用法: checker1 <输入文件> <选手输出文件> [答案文件]
//   - 答案文件可以不给（本校验器完全靠输入+选手输出就能判定）
//   - 输出 "ok" 或 "wrong answer: ..."
//
// 判定方式（严格、不依赖标程）：
//   1) 选手输出必须是恰好 Q 个整数；
//   2) 若输出 x != -1，则用出现位置表二分数出 x 在 [l,r] 的出现次数，
//      必须满足 cnt*q > (r-l+1)*p，否则 WA；
//   3) 若输出 -1，则必须真的不存在这样的 x：
//      用「线段树摘要」求出 [l,r] 内所有出现次数 > (r-l+1)/10 的候选（<=9 个，
//      因为出现次数超过 1/10 的数最多只有 9 个），逐个精确统计次数，
//      只要有一个满足条件就说明选手漏掉了答案 → WA。
#include <bits/stdc++.h>
using namespace std;

static const int K = 10;
static const int CAP = K - 1;

struct Sum
{
    int n;
    int v[CAP];
    int c[CAP];
    Sum() : n(0) {}
};

static void mergeSum(const Sum &A, const Sum &B, Sum &R)
{
    int tv[2 * CAP], tc[2 * CAP], m = 0;
    for (int i = 0; i < A.n; i++)
        tv[m] = A.v[i], tc[m] = A.c[i], m++;
    for (int i = 0; i < B.n; i++)
    {
        int x = B.v[i], at = -1;
        for (int j = 0; j < m; j++)
            if (tv[j] == x)
            {
                at = j;
                break;
            }
        if (at >= 0)
            tc[at] += B.c[i];
        else
            tv[m] = x, tc[m] = B.c[i], m++;
    }
    while (m >= K)
    {
        for (int i = 1; i < m; i++)
        {
            int kc = tc[i], kv = tv[i], j = i - 1;
            while (j >= 0 && tc[j] > kc)
                tc[j + 1] = tc[j], tv[j + 1] = tv[j], j--;
            tc[j + 1] = kc, tv[j + 1] = kv;
        }
        int d = tc[0];
        for (int j = 0; j < K; j++)
            tc[j] -= d;
        int nm = 0;
        for (int j = 0; j < m; j++)
            if (tc[j] > 0)
                tv[nm] = tv[j], tc[nm] = tc[j], nm++;
        m = nm;
    }
    R.n = m;
    for (int i = 0; i < m; i++)
        R.v[i] = tv[i], R.c[i] = tc[i];
}

[[noreturn]] static void wa(const string &msg)
{
    printf("wrong answer: %s\n", msg.c_str());
    exit(0);
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("usage: checker1 <input> <output> [answer]\n");
        return 1;
    }
    FILE *fi = fopen(argv[1], "r");
    FILE *fo = fopen(argv[2], "r");
    if (!fi || !fo)
        wa("cannot open file");

    int n, Q;
    if (fscanf(fi, "%d %d", &n, &Q) != 2)
        wa("input format error");
    if (n <= 0 || Q < 0)
        wa("invalid input");

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        if (fscanf(fi, "%d", &a[i]) != 1)
            wa("input format error");

    vector<int> ys = a;
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    int m = (int)ys.size();
    vector<int> id(n);
    for (int i = 0; i < n; i++)
        id[i] = (int)(lower_bound(ys.begin(), ys.end(), a[i]) - ys.begin());

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

    int sz = 1;
    while (sz < n)
        sz <<= 1;
    vector<Sum> tr(2 * sz);
    for (int i = 0; i < n; i++)
    {
        tr[sz + i].n = 1;
        tr[sz + i].v[0] = id[i];
        tr[sz + i].c[0] = 1;
    }
    for (int i = sz - 1; i >= 1; i--)
        mergeSum(tr[2 * i], tr[2 * i + 1], tr[i]);

    // 值 -> 编号（判断选手输出的数是否存在）
    auto cntIn = [&](int value, int l, int r) -> long long
    {
        auto it = lower_bound(ys.begin(), ys.end(), value);
        if (it == ys.end() || *it != value)
            return 0;
        int v = (int)(it - ys.begin());
        uint32_t A = st[v], B = st[v + 1];
        return (long long)(upper_bound(flat.begin() + A, flat.begin() + B, (uint32_t)r) -
                           lower_bound(flat.begin() + A, flat.begin() + B, (uint32_t)l));
    };

    Sum acc, tmp;
    for (int qi = 1; qi <= Q; qi++)
    {
        int l, r;
        long long p, q;
        if (fscanf(fi, "%d %d %lld %lld", &l, &r, &p, &q) != 4)
            wa("input format error");
        if (!(1 <= l && l <= r && r <= n) || !(1 <= p && p < q))
            wa("input format error (query)");
        if (p * 10 < q) // 题面保证 p/q >= 1/10，否则校验器无法判定 -1
            wa("data error: p/q < 1/10");
        long long len = r - l + 1;
        long long need = len * p;

        long long x;
        if (fscanf(fo, "%lld", &x) != 1)
            wa("第 " + to_string(qi) + " 个询问：输出不足 Q 个数（或格式错误）");

        if (x == -1)
        {
            // 检验真的无解
            acc.n = 0;
            for (int L = l - 1 + sz, R = r - 1 + sz + 1; L < R; L >>= 1, R >>= 1)
            {
                if (L & 1)
                {
                    mergeSum(acc, tr[L], tmp);
                    acc = tmp;
                    L++;
                }
                if (R & 1)
                {
                    R--;
                    mergeSum(acc, tr[R], tmp);
                    acc = tmp;
                }
            }
            for (int i = 0; i < acc.n; i++)
            {
                int value = ys[acc.v[i]];
                long long c = cntIn(value, l, r);
                if (c * q > need)
                    wa("第 " + to_string(qi) + " 个询问：不应该输出 -1，区间 [" + to_string(l) + "," +
                       to_string(r) + "] 内 " + to_string(value) + " 出现 " + to_string(c) + " 次，" +
                       to_string(c) + "*" + to_string(q) + " > " + to_string(len) + "*" + to_string(p) +
                       " = " + to_string(need) + "，是合法答案");
            }
        }
        else
        {
            if (x < 1 || x > 1000000000LL)
                wa("第 " + to_string(qi) + " 个询问：输出 " + to_string(x) + " 不可能是答案（数据范围 1..1e9）");
            long long c = cntIn((int)x, l, r);
            if (c * q <= need)
                wa("第 " + to_string(qi) + " 个询问：输出 " + to_string(x) + "，它在区间内出现 " +
                   to_string(c) + " 次，不满足 " + to_string(c) + "*" + to_string(q) + " > " + to_string(need));
        }
    }
    // 输出不能有多余内容
    long long extra;
    if (fscanf(fo, "%lld", &extra) == 1)
        wa("输出多了多余的数字");
    printf("ok\n");
    return 0;
}
