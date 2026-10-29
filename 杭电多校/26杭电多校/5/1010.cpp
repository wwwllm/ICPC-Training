#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100;
struct Basis
{
    vector<bitset<N>> p;
    vector<int> val;
    int cnt = 0;
    bool can_zero;
    Basis()
    {
        p.assign(N, 0);
        val.assign(N, 0);
        can_zero = 0;
    }
    // 插入元素
    void insert(bitset<N> x, int sg)
    {
        for (int i = N - 1; i >= 0; i--)
        {
            if (x[i] == 0)
                continue;
            if (p[i].none())
            {
                p[i] = x;
                val[i] = sg;
                return;
            }
            x ^= p[i];
            sg ^= val[i];
        }
        can_zero = 1;
    }
};
void solve()
{
    int k;
    cin >> k;
    Basis B;
    for (int i = 0; i < k; i++)
    {
        int siz, sg;
        cin >> siz >> sg;
        bitset<N> x(0);
        for (int i = 0; i < siz; i++)
        {
            int l;
            cin >> l;
            l--;
            x[l] = x[l] ^ 1;
        }
        B.insert(x, sg);
    }
    int q;
    cin >> q;
    auto &p = B.p;
    auto &val = B.val;
    while (q--)
    {
        int siz;
        cin >> siz;
        bitset<N> x(0);
        for (int i = 0; i < siz; i++)
        {
            int l;
            cin >> l;
            l--;
            x[l] = x[l] ^ 1;
        }
        bool ok = 1;
        int res = 0;
        for (int i = N - 1; i >= 0; i--)
        {
            if (x[i] == 1)
            {
                if (p[i].any())
                {
                    res ^= val[i];
                    x ^= p[i];
                }
                else
                    ok = 0;
            }
        }
        if (!ok)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << res << '\n';
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}