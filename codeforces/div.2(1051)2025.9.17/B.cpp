#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    vector<int> a(n + 1), b(k + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], ans += a[i];
    for (int i = 1; i <= k; i++)
        cin >> b[i];
    sort(b.begin() + 1, b.end());
    sort(a.begin() + 1, a.end(), greater<int>());
    int sum = 0;
    int j = 1;
    for (int i = 1; i <= k; i++)
    {
        if (sum + b[i] <= n)
        {

            sum += b[i];
            ans -= a[j + b[i] - 1];
            j += b[i];
        }
        else
            break;
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