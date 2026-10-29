// std1_det.cpp —— 抽奖 的确定性做法（备选解 / 用来验数据）
//
// 关键结论：一个区间里出现次数严格大于 (区间长度)/10 的数最多只有 9 个。
// 于是线段树每个结点只保存一个「摘要」：不超过 9 个 (值, 次数) 对，
// 且保证所有出现次数 > 结点长度/10 的值一定在摘要里。
// 合并两个摘要 = 先按值把次数相加（不同值最多 18 个），
//          然后反复「挑 10 个计数最小的不同值各减 1，减到 0 就扔掉」，直到不同值不足 10 个。
//          （每一步都等价于从多重集里删掉 10 个互不相同的元素，因此重值不会丢：
//            若某值真实出现次数 c > N/10 却被删光，则它参与了 t >= c 次删除，
//            每次删除还带走另外 9 个元素，于是 N >= 10t >= 10c，矛盾。）
// 询问 [l,r] 时把 log 个结点摘要合并，得到 <= 9 个候选值，
// 再用出现位置表二分数出每个候选在区间内的真实次数即可。整体 O((n + Q log n) log n)。
#include <bits/stdc++.h>
using namespace std;

static const int K = 10;      // 阈值 1/K
static const int CAP = K - 1; // 摘要里最多保留 K-1 个候选

struct Sum
{
    int n; // 不同值个数 (<= CAP)
    int v[CAP];
    int c[CAP];
    Sum() : n(0) {}
};

// 把 A、B 合并成 R（R 可以是 A/B 之外的新对象）
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
        // 按次数升序插入排序（m <= 18）
        for (int i = 1; i < m; i++)
        {
            int kc = tc[i], kv = tv[i], j = i - 1;
            while (j >= 0 && tc[j] > kc)
                tc[j + 1] = tc[j], tv[j + 1] = tv[j], j--;
            tc[j + 1] = kc, tv[j + 1] = kv;
        }
        int d = tc[0]; // 最小的计数
        for (int j = 0; j < K; j++)
            tc[j] -= d; // 10 个最小的不同值各减 d（逐个减 1 的批量写法）
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

/* ---------- 读入 ---------- */
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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = (int)readInt();

    vector<int> ys = a;
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    int m = (int)ys.size();
    vector<int> id(n);
    for (int i = 0; i < n; i++)
        id[i] = (int)(lower_bound(ys.begin(), ys.end(), a[i]) - ys.begin());

    // 值 -> 出现位置表
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

    // 线段树
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

    Sum acc, tmp;
    string out;
    out.reserve((size_t)Q * 8);
    for (int qi = 0; qi < Q; qi++)
    {
        int l, r;
        int64_t p, q;
        l = (int)readInt();
        r = (int)readInt();
        p = readInt();
        q = readInt();
        int64_t need = (int64_t)(r - l + 1) * p;
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
        int ans = -1;
        for (int i = 0; i < acc.n; i++)
        {
            int v = acc.v[i];
            uint32_t A = ST[v], B = ST[v + 1];
            if ((int64_t)(B - A) * q <= need)
                continue;
            int c = (int)(upper_bound(fl + A, fl + B, (uint32_t)r) - lower_bound(fl + A, fl + B, (uint32_t)l));
            if ((int64_t)c * q > need)
            {
                ans = ys[v];
                break;
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
