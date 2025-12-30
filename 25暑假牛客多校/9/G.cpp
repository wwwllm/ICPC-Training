#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 99824353;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        r[a[i]] = i;
    int ans = 0;
    for (int l = n; l >= 0; l++)
    {
        if (l == n)
            ans += 1, ans %= mod;
        else
        {
        }
    }
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