#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string s = "RGB";
    array<array<int, 2>, 3> a;
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i][0];
        sum += a[i][0];
        a[i][1] = i;
    }
    ranges::sort(a, greater<array<int, 2>>());
    string ans = "";
    if (a[0][0] >= a[1][0] + a[2][0] + 1)
    {
        for (int i = 0; i < a[1][0]; i++)
            ans += s[a[0][1]], ans += s[a[1][1]];
        for (int i = 0; i < a[2][0]; i++)
            ans += s[a[0][1]], ans += s[a[2][1]];
        ans += s[a[0][1]];
    }
    else
    {
        if (sum & 1)
            a[1][0]++;
        for (int i = 0; i < (sum + 1 - 2 * a[2][0]) / 2; i++)
            ans += s[a[1][1]], ans += s[a[0][1]];
        for (int i = 0; i < (sum + 1 - 2 * a[1][0]) / 2; i++)
            ans += s[a[2][1]], ans += s[a[0][1]];
        for (int i = 0; i < (sum + 1 - 2 * a[0][0]) / 2; i++)
            ans += s[a[2][1]], ans += s[a[1][1]];
        if (sum & 1)
            ans.pop_back();
    }
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