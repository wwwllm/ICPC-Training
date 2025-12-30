#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int ans = 0;
    for (int i = 1; i < n; i += 2)
    {
        if (i + 1 < n)
        {
            int tmp = a[i - 1] + a[i + 1];
            if (a[i] > tmp)
                continue;
            else
            {
                int cnt = tmp - a[i];
                ans += cnt;
                if (cnt > a[i + 1])
                {
                    a[i + 1] = 0;
                    cnt -= a[i + 1];
                    a[i - 1] -= cnt;
                }
                else
                    a[i + 1] -= cnt;
            }
        }
        else
        {
            if (a[i - 1] > a[i])
            {
                ans += a[i - 1] - a[i];
                a[i - 1] = a[i];
            }
        }
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