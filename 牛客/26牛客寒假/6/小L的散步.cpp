#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n, m, len;
    cin >> n >> m >> len;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    vector<int> b(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    int l = 0, r = len;
    int j = 1;
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        while (j <= n && pre[j] <= l)
            j++;
        while (j <= n && pre[j] < r)
        {
            cnt++;
            j++;
        }
        l += b[i], r += b[i];
    }
    while (j <= n && pre[j] <= l)
        j++;
    while (j <= n && pre[j] < r)
    {
        cnt++;
        j++;
    }
    cout << (cnt ? "YES" : "NO") << '\n';
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