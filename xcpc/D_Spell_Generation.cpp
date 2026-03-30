#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105945
void solve()
{
    int n;
    cin >> n;
    int ans = n % 10;
    n /= 10;
    int cur = 2;
    while (n)
    {
        int r = n % 10;
        ans += r * cur;
        n /= 10;
        cur <<= 1;
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