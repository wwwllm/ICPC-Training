#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> mpl, mpr;
    map<int, int> c;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        mpl[a[i]] = min(i, mpl[a[i]]);
        int j = i;
        while (j < n && a[i] == a[j])
            j++;
        if (c.count(a[i]))
            cnt++;
        c[a[i]]++;
        mpr[a[i]] = max(mpr[a[i]], i);
        i = j - 1;
    }
    if (cnt > 2)
    {
        cout << "NO\n";
        return;
    }
    else if (cnt == 0)
    {
        cout << "YES\n";
        return;
    }
    vector<int> ans(n);
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