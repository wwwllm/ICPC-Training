#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    auto clac = [&](int x)
    {
        int res = 1;
        while (x)
        {
            res *= x % 10;
            x /= 10;
        }
        return res;
    };
    int cnt = 0, ans = -1;
    for (int i = 2; i <= 1000000000; i++)
    {
        int tmp = 0;
        int x = i;
        while (x != clac(x))
        {
            x = clac(x);
            tmp++;
        }
        if (cnt < tmp)
        {
            cnt = tmp, ans = i;
        }
    }
    cout << ans << ' ' << cnt << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}