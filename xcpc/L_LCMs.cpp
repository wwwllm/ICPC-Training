#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105139
void solve()
{
    int a, b;
    cin >> a >> b;
    int ans = lcm(a, b);
    vector<int> p;
    for (int i = 2; i <= b / i; i++)
    {
        if (b % i == 0)
        {
            p.push_back(i), p.push_back(b / i);
        }
    }
    for (int i = 2; i <= a / i; i++)
    {
        if (a % i == 0)
        {
            p.push_back(i), p.push_back(a / i);
        }
    }
    for (int i = 2 * a; i <= b; i += a)
    {
        p.push_back(i);
    }
    for (auto x : p)
    {
        int res = lcm(b, x) + lcm(x, a);
        ans = min(res, ans);
    }
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