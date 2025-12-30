#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/1999/E
// 还可以用前缀和预处理所有1-2e5的数据
void solve()
{
    int l, r;
    cin >> l >> r;
    int p_3 = 1, cnt = 1;
    while (p_3 < l)
    {
        p_3 *= 3;
        cnt++;
    }
    if (p_3 != l)
        cnt--, p_3 /= 3;
    int ans = cnt;
    // cout << p_3 * 3 << '\n';
    while (p_3 * 3 <= r)
    {
        ans += (p_3 * 3 - max(p_3, l)) * (cnt);
        cnt++;
        p_3 *= 3;
    }
    ans += (r - max(p_3, l) + 1) * cnt;
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