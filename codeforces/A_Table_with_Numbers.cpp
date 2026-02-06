#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n, h, l;
    cin >> n >> h >> l;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cnt0 = 0, cnt1 = 0;
    for (auto x : a)
    {
        if (x <= min(h, l))
            cnt0++;
        else if (x <= max(h, l))
            cnt1++;
    }
    if (cnt1 > cnt0)
        cout << cnt0 << '\n';
    else
        cout << cnt1 + (cnt0 - cnt1) / 2 << '\n';
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