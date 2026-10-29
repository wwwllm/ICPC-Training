#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (!mp.count(x))
            cnt++;
        mp[x]++;
    }
    if (cnt <= 3)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}