// std2.cpp —— 抽奖 第二题（guess 做法）标程
//
// 结论：最后剩下的数可以是 k  ⇔  k <= n 且 k ≡ n(n+1)/2 (mod 2)
//
// 数据范围保证 1 <= n,k <= 1e9，n(n+1)/2 <= 5e17，所以在 64 位整数里算也不会溢出；
// 这里的写法更进一步：用 n % 4 直接判 n(n+1)/2 的奇偶，完全不产生大数。
//
// 必要性：
//   * 每次操作把 x,y 换成 |x-y|，而 |x-y| ≡ x+y (mod 2)，
//     所以「所有数之和」的奇偶性不变，最终剩下的数 ≡ 1+2+...+n = n(n+1)/2 (mod 2)；
//   * 任何时刻所有数都在 [0,n] 内（|x-y| <= max(x,y) <= n），因此最终值 k <= n。
// 充分性：
//   可以构造（归纳）。4 个连续整数 {a,a+1,a+2,a+3} 可以变成 0、2 或 4：
//     a,a+1 -> 1 且 a+2,a+3 -> 1，再 |1-1| = 0；
//     a,a+3 -> 3 且 a+1,a+2 -> 1，再 |3-1| = 2；
//     a+1,a+2 -> 1，再 |a-1| （或 a=1 时得 0），最后和 a+3 做差得到 4。
//   于是「把最后 4 个数整体压成 0/2/4，前面 n-4 个数递归变成 k'，最后 |k'-v|」，
//   由于 n 与 n-4 的 S 奇偶性相同，任何 k <= n-4 都能递归得到，
//   只剩最后 4 个位置附近的 k 需要单独验证（n <= 7 时直接爆搜验证即可）。
#include <bits/stdc++.h>
using namespace std;

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
static inline long long readInt()
{
    while (*ip && (*ip < '0' || *ip > '9') && *ip != '-')
        ++ip;
    bool neg = (*ip == '-');
    if (neg)
        ++ip;
    long long x = 0;
    while (*ip >= '0' && *ip <= '9')
        x = x * 10 + (*ip++ - '0');
    return neg ? -x : x;
}

int main()
{
    readAll();

    int t = (int)readInt();
    string out;
    out.reserve((size_t)t * 4);
    while (t--)
    {
        long long n = readInt();
        long long k = readInt();
        // S = n(n+1)/2 的奇偶：n%4 == 0 或 3 时为偶数，否则为奇数
        bool seven = (n % 4 == 0 || n % 4 == 3);
        bool keven = (k % 2 == 0);
        bool ok = (k >= 0 && k <= n) && (keven == seven);
        out += ok ? "Yes\n" : "No\n";
    }
    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}
