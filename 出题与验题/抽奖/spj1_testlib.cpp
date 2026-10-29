// spj1_testlib.cpp / chk.cc —— 抽奖 的 Special Judge（testlib 版）
//
// 一份代码两处用：
//   * 本地测试 / 对拍：
//       g++ -O2 -std=c++17 -I. -o spj1 spj1_testlib.cpp
//       ./spj1 1/dat9.in 1/dat9.out 1/dat9.out
//   * 提交到 OJ：把本文件原样复制成数据文件夹里的 chk.cc
//       （config.yaml 中 checker_type: testlib、checker: chk.cc；
//         testlib.h 由判题机提供，无需上传；注意扩展名必须是 .cc）
//     判题机按 testlib 约定调用：chk <input> <participant_output> <answer>
//
// 判定逻辑与 checker1.cpp 完全一致，且完全不依赖答案文件：
//   * 输出不是 -1：直接用出现位置表验证 cnt*q > (r-l+1)*p；
//   * 输出是 -1：用「线段树 + 10 路消去摘要」求出区间内所有出现次数 > (区间长度)/10 的候选
//     （最多 9 个），逐个精确统计，只要有一个满足条件就判 WA。
#include "testlib.h"
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

int main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);

    int n = inf.readInt();
    int Q = inf.readInt();
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = inf.readInt();

    vector<int> ys = a;
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    int m = (int)ys.size();
    vector<int> id(n);
    for (int i = 0; i < n; i++)
        id[i] = (int)(lower_bound(ys.begin(), ys.end(), a[i]) - ys.begin());

    vector<int> st(m + 1, 0);
    for (int i = 0; i < n; i++)
        st[id[i] + 1]++;
    for (int v = 0; v < m; v++)
        st[v + 1] += st[v];
    vector<int> flat(n);
    {
        vector<int> cur(st.begin(), st.end() - 1);
        for (int i = 0; i < n; i++)
            flat[cur[id[i]]++] = i + 1;
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

    auto countIn = [&](long long value, int l, int r) -> long long
    {
        auto it = lower_bound(ys.begin(), ys.end(), (int)value);
        if (it == ys.end() || *it != value)
            return 0;
        int v = (int)(it - ys.begin());
        int A = st[v], B = st[v + 1];
        return (long long)(upper_bound(flat.begin() + A, flat.begin() + B, r) -
                           lower_bound(flat.begin() + A, flat.begin() + B, l));
    };

    Sum acc, tmp;
    for (int qi = 1; qi <= Q; qi++)
    {
        int l = inf.readInt();
        int r = inf.readInt();
        long long p = inf.readLong();
        long long q = inf.readLong();
        if (p * 10 < q)
            quitf(_fail, "input data violates p/q >= 1/10 at query %d", qi);
        long long len = r - l + 1;
        long long need = len * p;

        long long x = ouf.readLong(-1, 1000000000LL, "answer");
        if (x == -1)
        {
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
                long long value = ys[acc.v[i]];
                long long c = countIn(value, l, r);
                if (c * q > need)
                    quitf(_wa, "query %d: answer is NOT -1: value %lld appears %lld times, %lld*%lld > %lld*%lld",
                          qi, value, c, c, q, len, p);
            }
        }
        else
        {
            long long c = countIn(x, l, r);
            if (c * q <= need)
                quitf(_wa, "query %d: value %lld appears %lld times, %lld*%lld <= %lld*%lld",
                      qi, x, c, c, q, len, p);
        }
    }
    if (!ouf.seekEof())
        quitf(_pe, "extra output after %d answers", Q);
    quitf(_ok, "%d queries checked", Q);
}
