#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 2), b(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    int ans = 0;
    a[0] = a[n + 1] = 1;
    vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                         31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
                         73, 79, 83, 89, 97, 101, 103, 107, 109, 113};
    vector<int> g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        g[i] = lcm(gcd(a[i], a[i - 1]), gcd(a[i], a[i + 1]));
    }
    vector<array<int, 2>> dp = {{a[0], 0}};
    for (int i = 1; i <= n; i++)
    {
        vector<array<int, 2>> tmp;
        tmp.push_back({a[i], 0});
        if (g[i] <= b[i])
        {
            if (g[i] != a[i])
                tmp.push_back({g[i], 1});
            else
            {
                for (auto p : prime)
                {
                    int x = p * g[i];
                    if (x > b[i])
                        continue;
                    tmp.push_back({x, 1});
                }
            }
        }
        vector<array<int, 2>> ndp;
        for (auto [y, c] : tmp)
        {
            int res = -1;
            for (auto [x, cnt] : dp)
            {
                if (gcd(x, y) == gcd(a[i], a[i - 1]))
                {
                    res = max(res, cnt + c);
                }
            }
            if (res != -1)
                ndp.push_back({y, res});
        }
        dp = ndp;
    }
    for (auto [x, cnt] : dp)
        ans = max(ans, cnt);
    cout << ans << '\n';
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