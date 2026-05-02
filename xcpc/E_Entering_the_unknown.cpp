#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/106380
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    auto calc = [&](int x)
    {
        int res = 0;
        while (x)
        {
            res = max(res, x % 10);
            x /= 10;
        }
        return res;
    };
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = calc(a[i]);
    }
    int ans = 0;
    for (int i = 1; i < 10; i++)
    {
        int cur = 0, ma = 0;
        map<int, int> mp1, mp2;
        mp1[0] = 1;
        for (int j = 1; j <= n; j++)
        {
            if (b[j] > i)
            {
                mp1.clear(), mp2.clear();
                mp1[0] = 1;
                cur = 0;
                ma = 0;
                continue;
            }
            ma = max(ma, b[j]);
            cur += a[j];
            cur %= i;
            if (b[j] == i)
            {
                for (auto [x, c] : mp1)
                    mp2[x] += c;
                mp1.clear();
            }
            mp1[cur]++;
            if (ma == i)
            {
                ans += mp2[cur];
            }
        }
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