#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector a(n + 1, vector<int>{});
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        int l;
        cin >> l;
        for (int j = 0; j < l; j++)
        {
            int x;
            cin >> x;
            mp[x]++;
            a[i].pb(x);
        }
        ranges::sort(a[i]);
    }
    vector<int> mex1(n + 1), mex2(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int p = 0;
        for (auto x : a[i])
            if (p == x)
                p++;
        mex1[i] = p;
        sum += p;
        p++;
        for (auto x : a[i])
            if (p == x)
                p++;
        mex2[i] = p;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        auto &aa = a[i];
        for (int j = 0; j < aa.size(); j++)
        {
            ans += (n - 1) * sum;
            if (mex1[i] <= aa[j] || (j > 0 && aa[j] == aa[j - 1]) || (j < aa.size() - 1 && aa[j] == aa[j + 1]))
                continue;
            ans -= (n - 1) * (mex1[i] - aa[j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (mp[mex1[i]])
            ans += mp[mex1[i]] * (mex2[i] - mex1[i]);
    }
    cout << ans << '\n';
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