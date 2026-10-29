#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    vector<int> pre(n + 1);
    vector<int> d(n + 1);
    for (int c = 1; c <= k; c++)
    {
        for (int i = 1; i <= n; i++)
        {
            d[i] = b[i] - a[i];
            pre[i] = pre[i - 1] + d[i];
        }
        int mi = 0, mil = 0;
        int l = -1, r = -1;
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            int tmp = pre[i] - mi;
            if (tmp > res)
            {
                res = tmp;
                l = mil + 1, r = i;
            }
            if (pre[i] < mi)
            {
                mi = pre[i];
                mil = i;
            }
        }
        if (l == -1 && r == -1)
        {
            break;
        }
        cerr << l << ' ' << r << '\n';
        for (int i = l; i <= r; i++)
            swap(a[i], b[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += a[i];
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}