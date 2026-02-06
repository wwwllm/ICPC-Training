#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n, a0, a1;
    cin >> n >> a0 >> a1;
    vector<int> ans;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs((cnt0 + 1) * a0 - cnt1 * a1) >= abs(cnt0 * a0 - (cnt1 + 1) * a1))
            ans.pb(0),cnt1++;
        else
            ans.pb(1),cnt0++;
    }
    for (auto x : ans)
        cout << x;
    cout << '\n';
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