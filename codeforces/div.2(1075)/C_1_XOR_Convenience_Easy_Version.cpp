#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> ans(n);
    ans[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        ans[i] = ans[n - 1] ^ (i + 1);
    }
    if (n & 1)
        ans[0] = n ^ 1;
    else
        ans[0] = n;
    for (int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i == n - 1];
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