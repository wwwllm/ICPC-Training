#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://qoj.ac/contest/2530
const int mod = 998244353, N = 1e3;
struct Basis
{
    long long p[64], d[64];
    int cnt = 0;
    bool can_zero;
    Basis()
    {
        memset(p, 0, sizeof(p));
        can_zero = 0;
    }
    // 插入元素
    void insert(long long x)
    {
        for (int i = 62; i >= 0; i--)
        {
            if (!(x >> i))
                continue;
            if (!p[i])
            {
                p[i] = x;
                return;
            }
            x ^= p[i];
        }
        can_zero = 1;
    }
    // 查询最大异或值
    long long query()
    {
        long long res = 0;
        for (int i = 62; i >= 0; i--)
        {
            res = max(res, res ^ p[i]);
        }
        return res;
    }
    // 合并线性基
    void merge(const Basis &b)
    {
        for (int i = 62; i >= 0; i--)
        {
            if (b.p[i])
                insert(b.p[i]);
        }
    }
    void rebuild()
    {
        cnt = 0;
        for (int i = 62; i >= 0; i--)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if ((p[i] >> j) & 1)
                    p[i] ^= p[j];
            }
        }

        for (int i = 0; i <= 62; i++)
        {
            if (p[i])
                d[cnt++] = p[i];
        }
    }

    long long kth(long long k)
    {
        if (can_zero)
            k--; // 如果原集合能异或出0，第k小要减1
        if (k >= (1LL << cnt))
            return -1;
        long long res = 0;
        for (int i = 0; i < cnt; i++)
        {
            if ((k >> i) & 1)
                res ^= d[i];
        }
        return res;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    int sa = 0, sb = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sa ^= a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        sb ^= b[i];
    }
    Basis B;
    for (int i = 0; i < n; i++)
        B.insert(a[i] ^ b[i]);
    for (int i = 31; i >= 0; i--)
    {
        if (max(sa, sb) > max(sa ^ B.p[i], sb ^ B.p[i]))
            sa ^= B.p[i], sb ^= B.p[i];
    }
    cout << max(sa, sb) << '\n';
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