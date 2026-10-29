#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int mask = 0;
    auto change = [&](int mask, int &a, int b) -> bool
    {
        int x = a | mask;
        if (x < b)
            return 0;
        for (int i = 30; i >= 0; i--)
        {
            if ((mask >> i & 1) && (x >> i & 1))
            {
                int nx = x - (1LL << i);
                if (nx >= b)
                    x = nx;
            }
        }
        a = x;
        return 1;
    };
    for (int bit = 30; bit >= 0; bit--)
    {
        int nmsk = mask | ((1LL << bit) - 1);
        auto aa = a;
        bool ok = 1;
        for (int i = 1; i <= n && ok; i++)
        {
            ok &= change(nmsk, aa[i], aa[i - 1]);
        }

        if (!ok)
        {
            mask |= (1LL << bit);
        }
    }
    cout << mask << '\n';
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