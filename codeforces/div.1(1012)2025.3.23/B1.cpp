#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), c(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    int p = -1;
    for (int i = 0; i < n; i++)
    {
        c[i] = a[i] - b[i];
    }
    for (int i = 0; i < n; i++)
    {
        c.push_back(c[i]);
    }
    int ans = 1;
    for (int i = 0, j = 0; i < n;)
    {
        int sum = c[i];
        j = i + 1;
        while (sum > 0 && j < 2 * n)
        {
            sum += c[j++];
        }
        ans = max(ans, j - i);
        i = j;
    }
    cout << ans << endl;
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