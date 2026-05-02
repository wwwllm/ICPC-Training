#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 2), b(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    int ans = 0;
    a[0] = a[n + 1] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (lcm(gcd(a[i - 1], a[i]), gcd(a[i + 1], a[i])) < a[i])
            ans++;
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