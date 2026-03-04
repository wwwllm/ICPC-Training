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
    auto f = [&](int x)
    {
        int tmp = 0;
        while (x != clac(x))
        {
            x = clac(x);
            tmp++;
        }
        return tmp;
    };
    vector<int> a = {1, 2, 3, 6, 7, 8, 9};
    int num;
    int cnt = 0, ans = 0;
    function<void(int)> dfs = [&](int c)
    {
        if (c == 17)
        {
            int res = num;
            cout << num << '\n';
            if (clac(num) == clac(277777788888899))
                return;
            int tmp = f(res);
            if (tmp > cnt)
            {
                cnt = tmp;
                ans = res;
            }
            return;
        }
        for (auto x : a)
        {
            int r = num % 10;
            if (x >= r)
            {
                num = num * 10 + x;
                dfs(c + 1);
                num /= 10;
            }
        }
    };
    dfs(0);
    cout << cnt << ' ' << ans << '\n';
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
// 277777788888899
// 367777778888889
// 27777789999999999