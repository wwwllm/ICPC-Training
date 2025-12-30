#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), pre(n);
    for (auto &x : a)
        cin >> x, x %= 3;
    pre[0] = a[0] % 3;
    for (int i = 1; i < n; i++)
        pre[i] = (pre[i - 1] + a[i]) % 3;
    for (int l = 0; l < n - 2; l++)
    {
        for (int r = l + 1; r < n - 1; r++)
        {
            int sum1 = pre[l], sum2 = (pre[r] - pre[l] + 3) % 3, sum3 = (pre[n - 1] - pre[r] + 3) % 3;
            if (((sum1 == sum2 && sum2 == sum3) || (sum1 != sum2 && sum2 != sum3 && sum1 != sum3)))
            {
                cout << l + 1 << ' ' << r + 1 << '\n';
                return;
            }
        }
    }
    cout << 0 << ' ' << 0 << '\n';
    return;
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