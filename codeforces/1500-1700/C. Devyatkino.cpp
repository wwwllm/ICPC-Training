#include <bits/stdc++.h>
#define int long long
using namespace std;

int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans *= a;
        b >>= 1;
        a *= a;
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    auto check = [&](int x)
    {
        while (x)
        {
            int u = x % 10;
            x /= 10;
            if (u == 7)
                return 1;
        }
        return 0;
    };
    int ans = 100;
    for (int i = 1; i < 10; i++)
    {
        int tmp = exp(10, i) - 1;
        int x = n, res = 0;
        while (!check(x))
            x += tmp, res++;
        ans = min(ans, res);
    }
    cout << ans << '\n';
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