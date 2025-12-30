#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a[n] = 1e9;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int cnt = 0;
        while (a[i] > a[i + 1])
        {
            a[i]--;
            cnt++;
        }
        ans = max(ans, cnt);
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