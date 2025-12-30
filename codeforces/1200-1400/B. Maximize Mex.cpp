#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2021/B
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &ele : a)
        cin >> ele;
    sort(a.begin(), a.end());
    map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (mp[ans % x] >= 1)
        {
            mp[ans % x]--;
            ans++;
        }
        if (ans >= a[i])
            mp[a[i] % x]++;
        else
            break;
    }
    while (mp[ans % x] >= 1)
    {
        mp[ans % x]--;
        ans++;
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