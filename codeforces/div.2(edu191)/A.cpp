#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    int ans1 = (n + x + y - 1) / (x + y);

    int ans2 = 0;
    if (x * z >= n)
    {
        ans2 = (n + x - 1) / x;
    }
    else
    {
        ans2 = z + (n - x * z + x + 10 * y - 1) / (x + 10 * y);
    }

    cout << min(ans1, ans2) << "\n";
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