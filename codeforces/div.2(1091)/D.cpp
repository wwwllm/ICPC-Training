#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 2), p(k + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= k; i++)
        cin >> p[i];
    a[n + 1] = a[0] = a[p[1]];
    p[0] = 0;
    p[k + 1] = n + 1;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i <= k; i++)
    {
        int res = 0;
        for (int j = p[i] + 1; j <= p[i + 1]; j++)
        {
            if (a[j] != a[j - 1])
                res++;
        }
        sum += res;
        ans = max(ans, res);
    }
    cout << max(sum / 2, ans) << '\n';
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