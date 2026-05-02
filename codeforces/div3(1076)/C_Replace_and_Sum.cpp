#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = n; i >= 1; i--)
    {
        a[i] = max(a[i], b[i]);
        if (i + 1 <= n)
            a[i] = max(a[i], a[i + 1]);
    }
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + a[i];
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << ' ';
    }
    cout << '\n';
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