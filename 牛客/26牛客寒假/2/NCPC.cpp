#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<int> ans(n);
    int ma = *max_element(a.begin(), a.end());
    if (mp[ma] & 1)
    {
        for (int i = 0; i < n; i++)
            if (a[i] == ma)
                ans[i] = 1;
    }
    else
    {
        for (int i = 0; i < n; i++)
            if (a[i] != ma)
                ans[i] = 1;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i];
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