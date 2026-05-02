#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

int get_rev(int x)
{
    int res = 0;
    while (x)
    {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}
void solve()
{
    int l, r;
    cin >> l >> r;
    int ans = get_rev(r);
    int p10 = 10;
    while (1)
    {
        int tmp = (r / p10) * p10 - 1;
        if (tmp < l)
            break;
        ans = max(ans, get_rev(tmp));
        if (r / p10 == 0)
            break;
        p10 *= 10;
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