#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;
int a[N];
int cnt[33][2];
void solve()
{
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        int x = a[i];
        for (int k = 32; k >= 0; k--)
        {
            cnt[k][(x >> k) & 1]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = a[i];
        int res = 0;
        for (int k = 32; k >= 0; k--)
        {
            int u = (x >> k) & 1;
            res += cnt[k][!u] * (1LL << k);
        }
        ans = max(res, ans);
    }
    cout << ans << endl;
}
signed main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}