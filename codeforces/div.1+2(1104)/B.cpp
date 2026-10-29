#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= b[i])
            continue;
        else
        {
            int j = i;
            while (j <= n && a[j] > b[i])
                j++;
            if (j == n + 1)
            {
                cout << -1 << '\n';
                return;
            }
            for (int p = j; p >= i + 1; p--)
            {
                cnt++;
                swap(a[p], a[p - 1]);
            }
        }
    }
    cout << cnt << '\n';
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