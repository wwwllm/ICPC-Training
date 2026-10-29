#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), cnt(1e5 + 1);
    for (auto &x : a)
        cin >> x, cnt[x]++;
    int ans = *max_element(cnt.begin(), cnt.end());
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}