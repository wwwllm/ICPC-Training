#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    int ans = 0;
    int i = 0;
    while ((a[i] ^ a[n - 1]) & 1)
        i++;
    ans = i;
    i = n - 1;
    while ((a[i] ^ a[0]) & 1)
        i--;
    ans = min(ans, n - 1 - i);
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