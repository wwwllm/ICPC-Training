#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int inf = 1e18;
void solve()
{
    int n, k, h;
    cin >> n >> h >> k;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    vector<int> suf(n + 2);
    suf[n + 1] = 0;
    for (int i = n; i >= 1; i--)
    {
        suf[i] = max(suf[i + 1], a[i]);
    }
    int c = (h - 1) / sum;
    int r = h - c * sum;
    int ans = c * (n + k);
    int mi = inf, s = 0;
    for (int i = 1; i <= n; i++)
    {
        s += a[i];
        mi = min(a[i], mi);
        if (max(s, s - mi + suf[i + 1]) >= r)
        {
            cout << ans + i << '\n';
            return;
        }
    }
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