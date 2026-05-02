#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ranges::sort(a);
    int l = 0, r = n + 1;
    auto check = [&](int x) -> bool
    {
        vector<int> b;
        vector<int> t(x);
        for (int i = 0; i < n; i++)
        {
            if (a[i] < x && t[a[i]] == 0)
            {
                t[a[i]] = 1;
            }
            else
                b.push_back(a[i]);
        }
        int p = 0;
        while (p < x && t[p] == 1)
            p++;
        if (p == x)
            return 1;
        for (auto y : b)
        {
            while (p < x && t[p] == 1)
                p++;
            if (p == x)
                return 1;
            if (y >= p * 2 + 1)
            {
                t[p] = 1;
                while (p < x && t[p] == 1)
                    p++;
            }
        }
        return p >= x;
    };
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}