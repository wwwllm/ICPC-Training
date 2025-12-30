#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2000/D
typedef long long ll;
void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    string s;
    cin >> s;
    s = '0' + s;
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    int l = 1, r = n;
    ll ans = 0;
    while (l < r)
    {
        while (l < r && s[l] == 'R')
            l++;
        while (l < r && s[r] == 'L')
            r--;
        if (l < r)
        {
            ans += pre[r] - pre[l - 1];
            l++, r--;
        }
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