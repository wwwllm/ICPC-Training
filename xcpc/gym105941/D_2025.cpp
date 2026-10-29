#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/gym/105941
void solve()
{
    auto sum = [&](int x) -> int
    {
        int ans = 0;
        while (x)
        {
            ans += x % 10;
            x /= 10;
        }
        return ans;
    };
    auto check = [&](int x)
    {
        for (int i = 1; i <= x / i; i++)
        {
            if (i * i == x)
                return 1;
        }
        return 0;
    };
    int n;
    cin >> n;
    if (check(n) && check(sum(n)))
        cout << "Yes\n";
    else
        cout << "No\n";
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