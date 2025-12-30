#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
        j = max(i, j);
        while (j + 1 < n && a[j + 1] <= a[j] + 1 && a[j + 1] - a[i] < k)
            j++;
        ans = max(ans, j - i + 1);
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