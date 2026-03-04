#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(64);
    auto insert = [&](int x)
    {
        for (int i = 60; i >= 0; i--)
        {
            if ((x >> i) & 1)
            {
                if (!p[i])
                {
                    p[i] = x;
                    return;
                }
                x ^= p[i];
            }
        }
    };
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        insert(x);
    }
    int ans = 0;
    for (int i = 60; i >= 0; i--)
    {
        ans = max(ans, ans ^ p[i]);
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--)
        solve();
    return 0;
}