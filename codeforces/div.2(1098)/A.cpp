#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> cnt(3, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ans = cnt[0] + min(cnt[1], cnt[2]);
    int d = min(cnt[1], cnt[2]);
    cnt[1] -= d, cnt[2] -= d;
    ans += cnt[1] / 3 + cnt[2] / 3;
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