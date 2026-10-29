#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int T = 10;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    auto change = [&]()
    {
        vector<int> aa(n);
        auto mex = [&](array<int, 3> x)
        {
            ranges::sort(x);
            int res = 0;
            for (int i = 0; i < 3; i++)
            {
                if (x[i] == res)
                    res++;
            }
            return res;
        };
        for (int i = 0; i < n; i++)
        {
            aa[i] = mex({a[i], a[(i + 1) % n], a[(i + n - 1) % n]});
        }
        a = aa;
    };
    if (k <= T)
    {
        for (int i = 0; i < k; i++)
        {
            change();
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " \n"[i == n - 1];
        }
    }
    else
    {
        for (int i = 0; i < T; i++)
        {
            change();
        }
        if (k & 1)
            change();
        for (int i = 0; i < n; i++)
            cout << a[i] << " \n"[i == n - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}