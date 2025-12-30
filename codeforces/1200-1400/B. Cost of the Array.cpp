#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2059/B
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    if (k == n)
    {
        int ans = 1;
        for (int i = 1; i < n; i += 2)
        {
            if (a[i] != ans)
                break;
            ans++;
        }
        cout << ans << endl;
        return;
    }
    for (int i = 1; i <= n - k + 1; i++)
    {
        if (a[i] != 1)
        {
            cout << 1 << endl;
            return;
        }
    }
    cout << 2 << endl;
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