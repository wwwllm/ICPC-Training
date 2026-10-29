#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    auto is_prime = [&](int x) -> bool
    {
        if (x == 1)
            return 0;
        if (x == 2)
            return 1;
        for (int i = 2; i <= x / i; i++)
        {
            if (x % i == 0)
                return 0;
        }
        return 1;
    };
    ranges::iota(a, 1);
    if (is_prime(n - 1) && n > 5)
    {
        reverse(a.end() - 4, a.end());
    }
    auto check = [&]()
    {
        for (int i = 0; i < n; i++)
        {
            if (is_prime(abs(a[i] - a[(i + 1) % n])))
                return 0;
        }
        return 1;
    };
    if (check())
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << " \n"[i == n - 1];
    }
    else
    {
        cout << "-1\n";
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