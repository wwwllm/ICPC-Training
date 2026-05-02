#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<array<int, 2>> b(n + 1);
    for (int i = 0; i < n; i++)
    {
        b[i + 1][0] = b[i][0] + a[i];
        b[i + 1][1] = i + 1;
    }
    sort(b.begin() + 1, b.end(), greater<array<int, 2>>());
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ans[b[i][1]] = i;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
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