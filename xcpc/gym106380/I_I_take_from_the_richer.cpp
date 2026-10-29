#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/106380
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    int res = a[0];
    for (int i = 1; i < n; i++)
    {
        if (res >= a[i])
            continue;
        res = (res + a[i] + 1) / 2;
    }
    cout << res << '\n';
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