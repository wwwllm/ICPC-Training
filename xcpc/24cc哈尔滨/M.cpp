#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n;
    cin >> n;
    vector<int> d;
    for (int i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            d.push_back(i);
            if (n != i * i)
                d.push_back(n / i);
        }
    }
    ranges::sort(d);
    int m = d.size();
    int ans = 0;
    int cur = n + 1;
    for (int i = m - 1; i >= 0; i--)
    {
        ans += (cur - d[i]) * (n / d[i]);
        cur = d[i];
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