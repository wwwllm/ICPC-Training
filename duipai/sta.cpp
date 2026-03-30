#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    auto check = [&](int x)
    {
        int a = 4, b = 100;
        int cnt = 0;
        while (a <= x)
        {
            if (x % a == 0 && x % b != 0)
                cnt++;
            a = a * 100, b = b * 100;
        }
        return cnt == 1;
    };
    int cnt = 0;
    for (int i = 1; i <= 2024; i++)
    {
        if (!check(i))
        {
            cnt++;
        }
    }
    cout << cnt << '\n';
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